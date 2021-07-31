#pragma once

#include <Meow/Core.h>
#include <Meow/Renderer/Buffer.h>

namespace Meow
{
	class MEOW_API OpenGLBuffer : public Buffer
	{
	private:
		unsigned int m_BufferId;
		unsigned int m_Count;
	public:
		OpenGLBuffer(const void* data, unsigned int count);
		~OpenGLBuffer();

		inline unsigned int getCount() const override { return m_Count; }

		void bind() const override;
		void unbind() const override;
	};
}