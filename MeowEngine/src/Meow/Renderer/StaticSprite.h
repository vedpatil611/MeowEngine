#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderable2D.h"

namespace Meow
{
	class MEOW_API StaticSprite: public Renderable2D
	{
	private:
		Shader* m_Shader;
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
	public:
		StaticSprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour, Shader* shader);
		~StaticSprite() override;

		inline const VertexArray* getVAO() const override { return m_VertexArray; }
		inline const IndexBuffer* getIBO() const override { return m_IndexBuffer; }
		inline Shader* getShader() const override { return m_Shader; }

		inline const Maths::vec3& getPositions() const { return m_Position; }
		inline const Maths::vec2& getSize() const { return m_Size; }
		inline const Maths::vec4& getColour() const { return m_Colour; }
	};
}