#include "MeowPCH.h"
#include "IndexBuffer.h"

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
		}
	}
}