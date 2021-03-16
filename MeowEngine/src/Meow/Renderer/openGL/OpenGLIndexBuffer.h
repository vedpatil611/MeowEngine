#pragma once

#include <Meow/Core.h>
#include <Meow/Renderer/IndexBuffer.h>

namespace Meow
{
	class MEOW_API OpenGLIndexBuffer : public IndexBuffer 
	{
	private:
		unsigned int m_BufferID;
	public:
		OpenGLIndexBuffer(const unsigned short* data, unsigned int count);
		~OpenGLIndexBuffer();

		void bind() const override;
		void unbind() const override;
	};
}