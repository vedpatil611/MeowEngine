#include "Buffer.h"

#include <Meow/Renderer/Renderer.h>

namespace Meow
{
	Buffer::Buffer(const void* data, unsigned int count, unsigned componentCount)
		:m_ComponentCount(componentCount)
	{
		GLCALL(glGenBuffers(1, &m_BufferId));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_BufferId));
		GLCALL(glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	Buffer::~Buffer()
	{
		GLCALL(glDeleteBuffers(1, &m_BufferId));
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
