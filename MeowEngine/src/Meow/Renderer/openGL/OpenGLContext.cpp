#include <MeowPCH.h>
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace Meow
{
	OpenGLContext::OpenGLContext(GLFWwindow* window)
		:m_Window(window) { }
	
	void OpenGLContext::init()
	{
		glfwMakeContextCurrent(m_Window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			throw std::runtime_error("Failed to init glad");

	}

	void OpenGLContext::swapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}
}
