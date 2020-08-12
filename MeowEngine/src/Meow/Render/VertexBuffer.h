#pragma once

#include <Meow/Core.h>

namespace Meow 
{
	class MEOW_API VertexBuffer
	{
	private:
		unsigned int m_BufferId;
		unsigned int m_ComponentCount;
	public:
		VertexBuffer(const void* data, unsigned int count, unsigned componentCount);
		~VertexBuffer();

		inline unsigned int getBufferId() const { return m_BufferId; }
		inline unsigned int getComponentCount() const { return m_ComponentCount; }

		void bind() const;
		void unbind() const;
	};
}
