#pragma once

#include <Meow/Core.h>

namespace Meow
{
	class MEOW_API IndexBuffer
	{
	public:
		virtual ~IndexBuffer();

		static IndexBuffer* create(const unsigned short* data, unsigned int count);
		virtual unsigned int getCount() const = 0;
		virtual void bind() const = 0;
		virtual void unbind() const = 0;
	};
}