#include "MeowPCH.h"
#include "BatchRenderer2D.h"

#include "glad/glad.h"

#define VERTEX_DATA_OFFSET(offset) (const void*) ((offset) * sizeof(float))
namespace Meow
{
	BatchRenderer2D::BatchRenderer2D()
		:m_IndexCount(0)
	{
		init();
	}

	BatchRenderer2D::~BatchRenderer2D()
	{
		GLCALL(glDeleteBuffers(1, &m_VAO));
		GLCALL(glDeleteBuffers(1, &m_VBO));
		delete m_IBO;
	}

	void BatchRenderer2D::begin()
	{
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));
		GLCALL(m_Buffer = (VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	}

	void BatchRenderer2D::submit(const Renderable2D* renderable)
	{
		const Maths::vec3& position = renderable->getPositions();
		const Maths::vec2& size = renderable->getSize();
		const Maths::vec4& colour = renderable->getColor();

		m_Buffer->vertex = position;
		m_Buffer->colour = colour;
		//m_Buffer->UV = { 0.0f, 0.0f };
		m_Buffer++;

		m_Buffer->vertex = { position.x, position.y + size.y, position.z };
		m_Buffer->colour = colour;
		//m_Buffer->UV = { 0.0f, 1.0f };
		m_Buffer++;

		m_Buffer->vertex = { position.x + size.x, position.y + size.y, position.z };
		m_Buffer->colour = colour;
		//m_Buffer->UV = { 1.0f, 1.0f };
		m_Buffer++;

		m_Buffer->vertex = { position.x + size.x, position.y, position.z };
		m_Buffer->colour = colour;
		//m_Buffer->UV = { 1.0f, 0.0f };
		m_Buffer++;
		
		++submitCount;
		m_IndexCount += 6;
	}

	void BatchRenderer2D::end()
	{
		GLCALL(glUnmapBuffer(GL_ARRAY_BUFFER));
		//GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	void BatchRenderer2D::flush()
	{
		GLCALL(glBindVertexArray(m_VAO));
		m_IBO->bind();

		GLCALL(glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, nullptr));

		//m_IBO->unbind();
		//GLCALL(glBindVertexArray(0));
	}

	void BatchRenderer2D::init() 
	{
		GLCALL(glGenBuffers(1, &m_VBO));
		GLCALL(glGenVertexArrays(1, &m_VAO));
		
		GLCALL(glBindVertexArray(m_VAO));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));
		GLCALL(glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, nullptr, GL_DYNAMIC_DRAW));
		
		GLCALL(glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, false, RENDERER_VERTEX_SIZE, VERTEX_DATA_OFFSET(0)));
		GLCALL(glVertexAttribPointer(SHADER_COLOUR_INDEX, 4, GL_FLOAT, false, RENDERER_VERTEX_SIZE, VERTEX_DATA_OFFSET(3)));
		//GLCALL(glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, false, RENDERER_VERTEX_SIZE, VERTEX_DATA_OFFSET(3 + 4)));
		GLCALL(glEnableVertexAttribArray(SHADER_VERTEX_INDEX));
		GLCALL(glEnableVertexAttribArray(SHADER_COLOUR_INDEX));
		//GLCALL(glEnableVertexAttribArray(SHADER_UV_INDEX));
		
		//GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
		
		unsigned short indices[RENDERER_INDICES_SIZE];
		
		for (int i = 0, offset = 0; i < RENDERER_INDICES_SIZE; i += 6, offset += 4)
		{
			indices[i]     = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;
		}

		m_IBO = new IndexBuffer(indices, RENDERER_INDICES_SIZE);
		//GLCALL(glBindVertexArray(0));
	}
}