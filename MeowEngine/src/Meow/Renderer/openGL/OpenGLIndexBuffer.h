#pragma once

#include <Meow/Core.h>
#include <Meow/Renderer/IndexBuffer.h>

namespace Meow
{
	class MEOW_API OpenGLIndexBuffer : public IndexBuffer 
	{
	private:
		unsigned int m_BufferID;
		unsigned int m_Count;
	public:
		OpenGLIndexBuffer(const unsigned short* data, unsigned int count);
		~OpenGLIndexBuffer();

		inline unsigned getCount() const override { return m_Count; }

		void bind() const override;
		void unbind() const override;
	};
}