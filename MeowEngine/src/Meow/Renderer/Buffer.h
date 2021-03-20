#pragma once

#include <Meow/Core.h>

namespace Meow
{
	class MEOW_API Buffer
	{
	public:
		virtual ~Buffer() {}

		static Buffer* create(const void* data, unsigned int count);

		virtual unsigned int getCount() const = 0;

		virtual void bind() const = 0;
		virtual void unbind() const = 0;
	};
}
