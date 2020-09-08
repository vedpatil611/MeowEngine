#pragma once

#include <Meow/Core.h>
#include "Buffer.h"
#include "MeowPCH.h"

namespace Meow {
	class MEOW_API VertexArray
	{
	private:
		unsigned int m_ArrayId;
		std::vector<Buffer*> *m_Buffers;
	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer* buffer, unsigned int index);

		void bind() const;
		void unbind() const;
	};
}