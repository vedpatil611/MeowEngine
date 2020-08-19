#pragma once

#include <Meow/Core.h>

namespace Meow
{
	class MEOW_API Buffer
	{
	private:
		unsigned int m_BufferId;
		unsigned int m_ComponentCount;
	public:
		Buffer(unsigned int buffer);
		Buffer(const void* data, unsigned int count, unsigned int componentCount);
		~Buffer();

		inline unsigned int getBufferId() const { return m_BufferId; }
		inline unsigned int getComponentCount() const { return m_ComponentCount; }

		void updateBufferData(const void* data, unsigned int count, unsigned int componentCount);
		void bind() const;
		void unbind() const;
	};
}
