#pragma once

#include <Meow/Core.h>
#include <Meow/Renderer/Buffer.h>

namespace Meow
{
	class MEOW_API OpenGLBuffer : public Buffer
	{
	private:
		unsigned int m_BufferId;
	public:
		OpenGLBuffer(const void* data, unsigned int count);
		~OpenGLBuffer();

		void bind() const override;
		void unbind() const override;
	};
}