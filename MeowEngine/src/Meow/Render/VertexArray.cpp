#include "VertexArray.h"

#include "Renderer.h"

namespace Meow
{
	VertexArray::VertexArray()
	{
		GLCALL(glGenVertexArrays(1, &m_ArrayId));
	}

	VertexArray::~VertexArray()
	{
		for (int i = 0; i < m_Buffers.size(); ++i)
			delete m_Buffers[i];
	}

	void VertexArray::addBuffer(VertexBuffer* buffer, unsigned int index)
	{
		bind();
		buffer->bind();

		GLCALL(glEnableVertexAttribArray(index));
		GLCALL(glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, false, 0, nullptr));

		buffer->unbind();
		unbind();
	}

	void VertexArray::bind() const
	{
		GLCALL(glBindVertexArray(m_ArrayId));
	}

	void VertexArray::unbind() const
	{
		GLCALL(glBindVertexArray(0));
	}
}