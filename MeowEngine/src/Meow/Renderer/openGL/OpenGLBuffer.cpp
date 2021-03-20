#include <MeowPCH.h>
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace Meow
{
	OpenGLBuffer::OpenGLBuffer(const void* data, unsigned int count)
		:m_Count(count)
	{
		GLCALL(glCreateBuffers(1, &m_BufferId));
		GLCALL(glBufferData(GL_ARRAY_BUFFER, count * sizeof(float), data, GL_DYNAMIC_DRAW));
	}

	OpenGLBuffer::~OpenGLBuffer()
	{
		GLCALL(glDeleteBuffers(1, &m_BufferId));
	}

	void OpenGLBuffer::bind() const
	{
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_BufferId));
	}
	
	void OpenGLBuffer::unbind() const
	{
		GLCALL(glDeleteBuffers(1, &m_BufferId));
	}
}