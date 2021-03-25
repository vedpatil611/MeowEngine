#pragma once

#include <Meow/Core.h>
#include "Buffer.h"
#include "MeowPCH.h"

namespace Meow {
	class MEOW_API VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		static VertexArray* create();

		virtual void addBuffer(Buffer* buffer, unsigned int index) = 0;

		virtual void bind() const = 0;
		virtual void unbind() const = 0;
	};
}