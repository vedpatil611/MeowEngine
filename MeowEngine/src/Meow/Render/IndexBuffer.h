#pragma once

#include <Meow/Core.h>
#include <Meow/Render/Buffer.h>

namespace Meow
{
	class MEOW_API IndexBuffer
	{
	private:
		unsigned int m_BufferID;
		unsigned int m_Count;
	public:
		IndexBuffer(const unsigned short int* data, unsigned int count);
		~IndexBuffer();

		inline unsigned int getBufferId() const { return m_BufferID; }
		inline unsigned short int getCount() const { return m_Count; }

		void bind() const;
		void unbind() const;
	};
}