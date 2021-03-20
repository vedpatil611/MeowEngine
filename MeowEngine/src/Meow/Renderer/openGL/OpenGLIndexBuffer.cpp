#include "MeowPCH.h"
#include "OpenGLIndexBuffer.h"

#include <glad/glad.h>

namespace Meow
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(const unsigned short* data, unsigned int count)
		:m_Count(count)
	{
		GLCALL(glGenBuffers(1, &m_BufferID));
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID));
		GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned short), data, GL_DYNAMIC_DRAW));
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		GLCALL(glDeleteBuffers(1, &m_BufferID));
	}
	
	void OpenGLIndexBuffer::bind() const
	{
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID));
	}
	
	void OpenGLIndexBuffer::unbind() const
	{
		GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}
}