#pragma once

#include "Meow/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Meow
{
	class MEOW_API OpenGLContext : public GraphicsContext
	{
	private:
		GLFWwindow* m_Window;
	public:
		OpenGLContext(GLFWwindow* window);

		void init() override;
		void swapBuffers() override;
	};
}