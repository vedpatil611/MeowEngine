#include "VertexBuffer.h"

#include <Meow/Render/Renderer.h>

namespace Meow
{
	VertexBuffer::VertexBuffer(const void* data, unsigned int count, unsigned componentCount)
		:m_ComponentCount(componentCount)
	{
		GLCALL(glGenBuffers(1, &m_BufferId));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_BufferId));
		GLCALL(glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_STATIC_DRAW));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	VertexBuffer::~VertexBuffer()
	{
		GLCALL(glDeleteBuffers(1, &m_BufferId));
	}
	void VertexBuffer::bind() const
	{
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_BufferId));
	}
	void VertexBuffer::unbind() const
	{
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}
