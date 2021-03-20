#include "MeowPCH.h"
#include "Meow/Core.h"

#include "glad/glad.h"
#include "VertexArray.h"

namespace Meow
{
	VertexArray::VertexArray()
	{
		GLCALL(glGenVertexArrays(1, &m_ArrayId));

		m_Buffers = new std::vector<Buffer*>();
	}

	VertexArray::~VertexArray()
	{
		for (int i = 0; i < m_Buffers->size(); ++i)
			delete (*m_Buffers)[i];

		delete m_Buffers;
	}

	void VertexArray::addBuffer(Buffer* buffer, unsigned int index)
	{
		bind();
		buffer->bind();

		GLCALL(glEnableVertexAttribArray(index));
		GLCALL(glVertexAttribPointer(index, buffer->getCount(), GL_FLOAT, false, 0, nullptr));
		m_Buffers->emplace_back(buffer);

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