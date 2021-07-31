#include "MeowPCH.h"
#include <Meow/Renderer/openGL/OpenGLVertexArray.h>

#include <glad/glad.h>

Meow::OpenGLVertexArray::OpenGLVertexArray()
{
	glGenVertexArrays(1, &m_ArrayId);
}

Meow::OpenGLVertexArray::~OpenGLVertexArray()
{
	for (int i = 0; i < m_Buffers.size(); ++i)
		delete m_Buffers[i];

	glDeleteVertexArrays(1, &m_ArrayId);
}

void Meow::OpenGLVertexArray::addBuffer(Buffer* buffer, unsigned int index)
{
	bind();
	buffer->bind();

	GLCALL(glEnableVertexAttribArray(index));
	GLCALL(glVertexAttribPointer(index, buffer->getCount(), GL_FLOAT, false, 0, nullptr));
	m_Buffers.emplace_back(buffer);

	buffer->unbind();
	unbind();
}

void Meow::OpenGLVertexArray::bind() const
{
	GLCALL(glBindVertexArray(m_ArrayId));
}

void Meow::OpenGLVertexArray::unbind() const
{
	GLCALL(glBindVertexArray(0));
}
