#pragma once

#include <Meow/Core.h>
#include "Buffer.h"

namespace Meow
{
	class MEOW_API IndexBuffer
	{
	private:
		unsigned int m_BufferID;
		unsigned int m_Count;
	public:
		virtual ~IndexBuffer();

		static IndexBuffer* create(const unsigned short* data, unsigned int count);

		virtual void bind() const = 0;
		virtual void unbind() const = 0;
	};
}