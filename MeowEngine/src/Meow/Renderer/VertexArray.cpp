#include "MeowPCH.h"
#include "VertexArray.h"

#include <Meow/Renderer/Renderer.h>
#include <Meow/Renderer/openGL/OpenGLVertexArray.h>
#include <stdexcept>

namespace Meow
{
	VertexArray* VertexArray::create()
	{
		switch (Renderer::getRendererAPI())
		{
		case RendererAPI::OpenGL:
			return new OpenGLVertexArray();
		default:
			throw std::runtime_error("Invalid renderer api");
		}
	}
}