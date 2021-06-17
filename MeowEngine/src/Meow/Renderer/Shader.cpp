#include "MeowPCH.h"
#include "Shader.h"

#include <Meow/Renderer/Renderer.h>
#include <Meow/Renderer/openGL/OpenGLShader.h>

namespace Meow {
	Shader* Shader::create(const char* vertPath, const char* fragPath)
	{
		switch (Renderer::getRendererAPI())
		{
		case RendererAPI::OpenGL:
			return new OpenGLShader(vertPath, fragPath);
		default:
			break;
		}
		return nullptr;
	}
}
