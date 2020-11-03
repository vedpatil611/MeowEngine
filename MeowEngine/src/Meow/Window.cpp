#include "MeowPCH.h"
#include "Window.h"

#include <glad/glad.h>
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
		//GLCALL(glClear(GL_COLOR_BUFFER_BIT));
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
		//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
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

	bool Window::setVSyncEnable(bool b)
	{
		glfwSwapInterval(static_cast<int>(b));
		return b;
	}

	void Window::windowResizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
	
	void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		//if (action == GLFW_PRESS)
			//m_PressedKey[key] = true;
		//else if (action == GLFW_RELEASE)
			//m_PressedKey[key] = false;
	}
}