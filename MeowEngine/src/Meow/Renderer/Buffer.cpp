#include "MeowPCH.h"
#include "Buffer.h"

#include "Meow/Renderer/Renderer.h"
#include "Meow/Renderer/openGL/OpenGLBuffer.h"

namespace Meow
{
	Buffer* Buffer::create(const void* data, unsigned int count)
	{
		switch (Renderer::getRendererAPI())
		{
		case RendererAPI::OpenGL:
			return new OpenGLBuffer(data, count);
		}
	}
}
