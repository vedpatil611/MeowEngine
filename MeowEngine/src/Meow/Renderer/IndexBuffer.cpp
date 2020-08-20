#include "MeowPCH.h"
#include "IndexBuffer.h"

#include "SimpleRenderer2D.h"

namespace Meow {
	IndexBuffer::IndexBuffer(const unsigned short* data, unsigned int count)
		:m_Count(count)
	{
		GLCALL(glGenBuffers(1, &m_BufferID));
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID));
		GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned short), data, GL_DYNAMIC_DRAW));
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	IndexBuffer::~IndexBuffer()
	{
		GLCALL(glDeleteBuffers(1, &m_BufferID));
	}

	void IndexBuffer::bind() const
	{
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID));
	}

	void IndexBuffer::unbind() const
	{
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}
}