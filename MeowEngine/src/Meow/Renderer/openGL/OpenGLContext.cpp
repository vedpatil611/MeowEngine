#include <MeowPCH.h>
#include <Meow/Renderer/openGL/OpenGLContext.h>

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

	void OpenGLContext::clear()
	{
		GLCALL(glClear(GL_COLOR_BUFFER_BIT));
	}

	void OpenGLContext::swapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}
}
