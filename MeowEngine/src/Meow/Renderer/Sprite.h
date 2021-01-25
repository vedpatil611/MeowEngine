#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderable2D.h"

namespace Meow
{
	class MEOW_API Sprite: public Renderable2D
	{
	private:
		Shader* m_Shader;
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
	public:
		Sprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour, Shader* shader);
		~Sprite() override;

		inline VertexArray* getVAO() const override { return m_VertexArray; }
		inline IndexBuffer* getIBO() const override { return m_IndexBuffer; }
		inline Shader* getShader() const override { return m_Shader; }
	};
}