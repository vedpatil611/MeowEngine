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
		Buffer(const void* data, unsigned int count, unsigned componentCount);
		~Buffer();

		inline unsigned int getBufferId() const { return m_BufferId; }
		inline unsigned int getComponentCount() const { return m_ComponentCount; }

		void bind() const;
		void unbind() const;
	};
}
