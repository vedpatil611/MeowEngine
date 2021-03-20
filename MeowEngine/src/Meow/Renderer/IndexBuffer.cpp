#include "MeowPCH.h"
#include "IndexBuffer.h"

#include <stdexcept>
#include <Meow/Renderer/Renderer.h>
#include <Meow/Renderer/openGL/OpenGLIndexBuffer.h>

namespace Meow {
	IndexBuffer::~IndexBuffer()
	{
	}

	IndexBuffer* IndexBuffer::create(const unsigned short* data, unsigned int count)
	{
		switch (Renderer::getRendererAPI())
		{
		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(data, count);
		default:
			throw std::runtime_error("Invalid renderer api");
		}
	}
}