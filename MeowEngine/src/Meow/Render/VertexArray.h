#pragma once

#include <Meow/Core.h>
#include <Meow/Render/VertexBuffer.h>
#include <vector>

namespace Meow {
	class MEOW_API VertexArray
	{
	private:
		unsigned int m_ArrayId;
		std::vector<VertexBuffer*> m_Buffers;
	public:
		VertexArray();
		~VertexArray();

		void addBuffer(VertexBuffer* buffer, unsigned int index);

		void bind() const;
		void unbind() const;
	};
}