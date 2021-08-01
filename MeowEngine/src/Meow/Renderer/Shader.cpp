#include "MeowPCH.h"
#include <Meow/Renderer/Shader.h>

#include <Meow/Renderer/Renderer.h>
#include <Meow/Renderer/openGL/OpenGLShader.h>

namespace Meow {
	Shader* Shader::create(const char* vertPath, const char* fragPath)
	{
		printf("%d\n", Renderer::getRendererAPI());
		switch (Renderer::getRendererAPI())
		{
		case RendererAPI::None:
			throw std::runtime_error("No renderer api specified");
		case RendererAPI::OpenGL:
			return new OpenGLShader(vertPath, fragPath);
		case RendererAPI::Vulkan:
			throw std::runtime_error("Vulkan not supported yet");
		}
	}
}
