#include "Window.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>

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

		setCurrentContext();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::update() 
	{
		glfwGetWindowSize(m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
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
		glfwSetWindowSize(window, width, height);
		glad_glViewport(0, 0, width, height);
	}
}