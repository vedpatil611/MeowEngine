#include "MeowPCH.h"
#include "Buffer.h"

#include "SimpleRenderer2D.h"

namespace Meow
{
	Buffer::Buffer(unsigned int buffer) : m_BufferId(buffer) {}

	Buffer::Buffer(const void* data, unsigned int count, unsigned int componentCount)
		:m_ComponentCount(componentCount)
	{
		GLCALL(glGenBuffers(1, &m_BufferId));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_BufferId));
		GLCALL(glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_DYNAMIC_DRAW));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	Buffer::~Buffer()
	{
		GLCALL(glDeleteBuffers(1, &m_BufferId));
	}
	
	void Buffer::updateBufferData(const void* data, unsigned int count, unsigned int componentCount)
	{
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_BufferId));
		GLCALL(glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_DYNAMIC_DRAW));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
	
	void Buffer::bind() const
	{
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_BufferId));
	}
	void Buffer::unbind() const
	{
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}
