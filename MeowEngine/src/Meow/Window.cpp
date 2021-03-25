#include "MeowPCH.h"
#include "Window.h"

#include <stdexcept>

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Renderer/Texture.h"
#include "Renderer/openGL/OpenGLContext.h"

namespace Meow {
	Window::Window(const char* title, int width, int height)
		:m_Title(title), m_Width(width), m_Height(height)
	{
		if (!glfwInit())
			throw std::runtime_error("Failed to init glfw");

		m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		if (!m_Window)
		{
			glfwTerminate();
			throw std::runtime_error("Failed to init glfw");
		}
		
		glfwSetWindowSizeCallback(m_Window, &Meow::Window::windowResizeCallback);
		glfwSetWindowCloseCallback(m_Window, &Meow::Window::windowCloseCallback);
		glfwSetKeyCallback(m_Window, &Meow::Window::keyCallback);
		glfwSetCharCallback(m_Window, &Meow::Window::charCallback);
		glfwSetMouseButtonCallback(m_Window, &Meow::Window::mouseButtonCallback);
		glfwSetCursorPosCallback(m_Window, &Meow::Window::cursorPosCallback);
		glfwSetScrollCallback(m_Window, &Meow::Window::scrollCallback);

		// 0 for vsync off
		glfwSwapInterval(0);

		m_Context = new OpenGLContext(m_Window);
		m_Context->init();
		
		GLCALL(glEnable(GL_BLEND));
		GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		GLCALL(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));

		glfwSetWindowUserPointer(m_Window, this);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	int Window::isJoystickPresent() const
	{
		return glfwJoystickPresent(GLFW_JOYSTICK_1);
	}

	void Window::update()
	{
		glfwPollEvents();
		if(isJoystickPresent())
			glfwGetGamepadState(GLFW_JOYSTICK_1, &gamepadState);

		m_Context->swapBuffers();
		GLCALL(glClear(GL_COLOR_BUFFER_BIT));
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}
	
	void Window::setCurrentContext() const
	{
		glfwMakeContextCurrent(m_Window);
	}

	bool Window::setVSyncEnable(bool b)
	{
		glfwSwapInterval(static_cast<int>(b));
		return b;
	}

	void Window::setBackgrondColor(const Meow::Maths::vec4& color)
	{
		GLCALL(glClearColor(color.r, color.g, color.b, color.a));
	}

	void Window::setIcon(const char* iconPath)
	{
		GLFWimage images[1];
		Texture icon(iconPath);
		images[0] = { icon.getWidth(), icon.getHeight(), icon.getPixels() };

		glfwSetWindowIcon(m_Window, 1, images);
	}

	double Window::getWindowTimeNow()
	{
		return glfwGetTime();
	}

	void Window::windowResizeCallback(GLFWwindow* window, int width, int height)
	{
		Window* currentWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
		glViewport(0, 0, width, height);
		currentWindow->m_Width = width;
		currentWindow->m_Height = height;

		WindowResizeEvent windowResizeEvent(width, height);
		currentWindow->eventCallback(windowResizeEvent);
	}
	
	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* currentWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

		switch (action)
		{
			case GLFW_PRESS:
			{
				currentWindow->m_PressedKey[key] = true;

				KeyPressedEvent keyEvent(key, 0);
				currentWindow->eventCallback(keyEvent);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent keyEvent(key, 1);
				currentWindow->eventCallback(keyEvent);
				break;
			}
			case GLFW_RELEASE:
			{
				currentWindow->m_PressedKey[key] = false;

				KeyReleasedEvent keyEvent(key);
				currentWindow->eventCallback(keyEvent);
				break;
			}
			default:
				break;
		}
	}

	void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* currentWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

		switch (action)
		{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				currentWindow->eventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				currentWindow->eventCallback(event);
				break;
			}
			default:
				break;
		}
	}

	void Window::cursorPosCallback(GLFWwindow* window, double xPos, double yPos)
	{
		Window* currentWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
		MouseMovedEvent event(xPos, yPos);
		currentWindow->eventCallback(event);
	}

	void Window::scrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{
		Window* currentWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

		MouseScrolledEvent event(xOffset, yOffset);
		currentWindow->eventCallback(event);
	}

	void Window::charCallback(GLFWwindow* window, unsigned int code)
	{
		Window* currentWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

		KeyTypedEvent event(code);
		currentWindow->eventCallback(event);
	}
	
	void Window::windowCloseCallback(GLFWwindow* window)
	{
		Window* currentWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

		WindowCloseEvent windowCloseEvent;
		currentWindow->eventCallback(windowCloseEvent);
	}
}