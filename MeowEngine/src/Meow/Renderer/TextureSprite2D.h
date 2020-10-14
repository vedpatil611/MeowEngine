#pragma once

#include <Meow/Core.h>

#include "IndexBuffer.h"
#include "Renderable2D.h"
#include "Shader.h"
#include "VertexArray.h"

namespace Meow
{
	class MEOW_API TextureSprite2D: public Renderable2D
	{
	private:
		Shader* m_Shader;
		const char* m_TexturePath;
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
	public:
		TextureSprite2D(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour, const char* texturePath, Shader* shader);
		~TextureSprite2D();

		inline const VertexArray* getVAO() const override { return m_VertexArray; }
		inline const IndexBuffer* getIBO() const override { return m_IndexBuffer; }
		inline Shader* getShader() const override { return m_Shader; }

		inline const Maths::vec3& getPositions() const { return m_Position; }
		inline const Maths::vec2& getSize() const { return m_Size; }
	};
}