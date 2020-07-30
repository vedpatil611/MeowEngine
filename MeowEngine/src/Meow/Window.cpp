#include "Window.h"

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

		glfwMakeContextCurrent(m_Window);
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::update() const
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}
}