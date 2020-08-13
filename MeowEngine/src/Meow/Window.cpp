#include "Window.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <Meow/Log.h>

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
		setCurrentContext();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::update() 
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glfwSwapBuffers(m_Window);
		glfwGetWindowSize(m_Window, &m_Width, &m_Height);
		glfwGetCursorPos(m_Window, &m_MouseX, &m_MouseY);
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}
	
	void Window::setCurrentContext() const
	{
		glfwMakeContextCurrent(m_Window);
	}

	void Window::windowResizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
	
	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		/*keyPressedState = (Meow::KeyActions) action;
		if (action == GLFW_PRESS)
			Window::m_PressedKey[key] = true;
		else if (action == GLFW_RELEASE)
			Window::m_PressedKey[key] = false;*/
	}
}