#include "MeowPCH.h"
#include "BatchRenderer2D.h"

#include "glad/glad.h"

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
		GLCALL(m_Buffer = (VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE));
	}

	void BatchRenderer2D::submit(const Renderable2D* renderable)
	{
		const Maths::vec3& position = renderable->getPositions();
		const Maths::vec2& size = renderable->getSize();
		const Maths::vec4& colour = renderable->getColour();

		m_Buffer->vertex = Maths::vec3(position.x, position.y, position.z);
		//m_Buffer->vertex = Maths::vec3(0.0f, 0.0f, 0.0f);
		m_Buffer->colour = colour;
		m_Buffer++;

		m_Buffer->vertex = Maths::vec3(position.x, position.y + size.y, position.z);
		//m_Buffer->vertex = Maths::vec3(0.0f, size.y, 0.0f);
		m_Buffer->colour = colour;
		m_Buffer++;

		m_Buffer->vertex = Maths::vec3(position.x + size.x, position.y + size.y, position.z);
		//m_Buffer->vertex = Maths::vec3(size.x, size.y, 0.0f);
		m_Buffer->colour = colour;
		m_Buffer++;

		m_Buffer->vertex = Maths::vec3(position.x + size.x, position.y, position.z);
		//m_Buffer->vertex = Maths::vec3(size.x, 0.0f, 0.0f);
		m_Buffer->colour = colour;
		m_Buffer++;
		
		//GLCALL(glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, m_Buffer, GL_DYNAMIC_DRAW));
		//renderable->getShader()->setUniformMat4f("u_model_mat", Maths::mat4::translation())
		m_IndexCount += 6;
	}

	void BatchRenderer2D::end()
	{
		GLCALL(glUnmapBuffer(GL_ARRAY_BUFFER));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	void BatchRenderer2D::flush()
	{
		GLCALL(glBindVertexArray(m_VAO));
		m_IBO->bind();

		GLCALL(glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, nullptr));

		m_IBO->unbind();
		GLCALL(glBindVertexArray(0));
	}

	void BatchRenderer2D::init() 
	{
		GLCALL(glGenBuffers(1, &m_VBO));
		GLCALL(glGenVertexArrays(1, &m_VAO));
		
		GLCALL(glBindVertexArray(m_VAO));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));
		GLCALL(glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, nullptr, GL_DYNAMIC_DRAW));
		
		GLCALL(glEnableVertexAttribArray(SHADER_VERTEX_INDEX));
		GLCALL(glEnableVertexAttribArray(SHADER_COLOUR_INDEX));
		GLCALL(glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, false, RENDERER_VERTEX_SIZE, (const void*) 0));
		GLCALL(glVertexAttribPointer(SHADER_COLOUR_INDEX, 4, GL_FLOAT, false, RENDERER_VERTEX_SIZE, (const void*) (3 * sizeof(float))));
		
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
		
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
		GLCALL(glBindVertexArray(0));
	}
}