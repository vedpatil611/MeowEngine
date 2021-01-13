#include "MeowPCH.h"
#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

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
		glfwSetKeyCallback(m_Window, &Meow::Window::keyCallback);
		glfwMakeContextCurrent(m_Window);

		// 0 for vsync off
		glfwSwapInterval(0);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			throw std::runtime_error("Failed to init glad");
		
		//GLCALL(glEnable(GL_TEXTURE_2D));
		//GLCALL(glEnable(GL_DEPTH_TEST));
		GLCALL(glEnable(GL_BLEND));
		GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		GLCALL(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));

		glfwSetWindowUserPointer(m_Window, this);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::update()
	{
		//if (m_PressedKey[GLFW_KEY_UP])
			//LOG << "pressed" << END_LOG;
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
		glfwGetWindowSize(m_Window, &m_Width, &m_Height);
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glfwGetCursorPos(m_Window, &m_MouseX, &m_MouseY);
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
		//GLCALL(glClear(GL_COLOR_BUFFER_BIT));
	}

	void Window::windowResizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
	
	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* currentWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
		if (action == GLFW_PRESS)
		{
			currentWindow->m_PressedKey[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			currentWindow->m_PressedKey[key] = false;
		}
	}
}