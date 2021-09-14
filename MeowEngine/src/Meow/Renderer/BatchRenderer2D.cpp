#include "MeowPCH.h"
#include <Meow/Renderer/BatchRenderer2D.h>

#include <algorithm>
#include "glad/glad.h"
#include <Meow/Renderer/IndexBuffer.h>

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
		//m_IndexCount = 0;
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));
		GLCALL(m_Buffer = (VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	}

	void BatchRenderer2D::submit(Rc<Renderable2D> renderable)
	{
		const Maths::vec3& position = renderable->getPositions();
		const Maths::vec2& size = renderable->getSize();
		const Maths::vec4& colour = renderable->getColor();
		const std::vector<Maths::vec2>& uvs = renderable->getUVs();
		const unsigned int tid = renderable->getTID();

		float textureSlot = -2.0f;
	
		if (tid > 0)
		{
			auto it = std::find(m_TexturesSlots.begin(), m_TexturesSlots.end(), tid);
			if (it != m_TexturesSlots.end())
			{
				textureSlot = static_cast<float>(it - m_TexturesSlots.begin());
			}
			else
			{
				if (m_TexturesSlots.size() >= 32)
				{
					end();
					flush(0.0f);

					begin();
				}
				m_TexturesSlots.emplace_back(tid);
				textureSlot = static_cast<float>(m_TexturesSlots.size() - 1);
			}
		}
		
		m_Buffer->vertex = position;
		m_Buffer->colour = colour;
		m_Buffer->UV = uvs[0];
		m_Buffer->tid = textureSlot;
		m_Buffer++;

		m_Buffer->vertex = { position.x, position.y + size.y, position.z };
		m_Buffer->colour = colour;
		m_Buffer->UV = uvs[1];
		m_Buffer->tid = textureSlot;
		m_Buffer++;

		m_Buffer->vertex = { position.x + size.x, position.y + size.y, position.z };
		m_Buffer->colour = colour;
		m_Buffer->UV = uvs[2];
		m_Buffer->tid = textureSlot;
		m_Buffer++;

		m_Buffer->vertex = { position.x + size.x, position.y, position.z };
		m_Buffer->colour = colour;
		m_Buffer->UV = uvs[3];
		m_Buffer->tid = textureSlot;
		m_Buffer++;
		
		++submitCount;
		m_IndexCount += 6;
	}
		
	void BatchRenderer2D::end()
	{
		GLCALL(glUnmapBuffer(GL_ARRAY_BUFFER));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	void BatchRenderer2D::flush(float delta)
	{
		for (int i = 0; i < m_TexturesSlots.size(); ++i)
		{
			GLCALL(glActiveTexture(GL_TEXTURE0 + i));
			GLCALL(glBindTexture(GL_TEXTURE_2D, m_TexturesSlots[i]));
		}

		GLCALL(glBindVertexArray(m_VAO));
		//m_IBO->bind();

		GLCALL(glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, nullptr));

		//m_IBO->unbind();
		GLCALL(glBindVertexArray(0));
	}

	void BatchRenderer2D::clear()
	{
		m_IndexCount = 0;
	}

	void BatchRenderer2D::init() 
	{
		GLCALL(glGenBuffers(1, &m_VBO));
		GLCALL(glGenVertexArrays(1, &m_VAO));
		
		GLCALL(glBindVertexArray(m_VAO));
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_VBO));
		GLCALL(glBufferData(GL_ARRAY_BUFFER, RENDERER_BUFFER_SIZE, nullptr, GL_DYNAMIC_DRAW));
		
		GLCALL(glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, false, RENDERER_VERTEX_SIZE, (const void*) offsetof(VertexData, VertexData::vertex)));
		GLCALL(glVertexAttribPointer(SHADER_COLOUR_INDEX, 4, GL_FLOAT, false, RENDERER_VERTEX_SIZE, (const void*) offsetof(VertexData, VertexData::colour)));
		GLCALL(glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, false, RENDERER_VERTEX_SIZE, (const void*) offsetof(VertexData, VertexData::UV)));
		GLCALL(glVertexAttribPointer(SHADER_TID_INDEX, 1, GL_FLOAT, false, RENDERER_VERTEX_SIZE, (const void*) offsetof(VertexData, VertexData::tid)));

		GLCALL(glEnableVertexAttribArray(SHADER_VERTEX_INDEX));
		GLCALL(glEnableVertexAttribArray(SHADER_COLOUR_INDEX));
		GLCALL(glEnableVertexAttribArray(SHADER_UV_INDEX));
		GLCALL(glEnableVertexAttribArray(SHADER_TID_INDEX));
		
		GLCALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
		
		unsigned short indices[RENDERER_INDICES_SIZE] = { 0 };
		
		for (int i = 0, offset = 0; i < RENDERER_INDICES_SIZE; i += 6, offset += 4)
		{
			indices[i]     = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;
		}

		m_IBO = IndexBuffer::create(indices, RENDERER_INDICES_SIZE);
		GLCALL(glBindVertexArray(0));
	}
}
