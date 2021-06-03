#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include <vector>

namespace Meow 
{ 

	struct VertexData {
		Maths::vec3 vertex;
		Maths::vec4 colour;
		Maths::vec2 UV;
	};

	struct Transformations2D
	{
		Maths::vec3 translation = { 0.0f, 0.0f, 0.0f };
		Maths::vec2 scale = { 1.0f, 1.0f};
		float rotation = 0.0f;
	};

	class MEOW_API Renderable2D
	{
	protected:
		Maths::vec3 m_Position;
		Maths::vec2 m_Size;
		Maths::vec4 m_Colour;
		std::vector<Maths::vec2> m_UVS;
	public:
		Renderable2D(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour);
		virtual ~Renderable2D();

		virtual inline VertexArray* getVAO() const = 0;
		virtual inline IndexBuffer* getIBO() const = 0;
		virtual inline Shader* getShader() const = 0;

		inline const Maths::vec3& getPositions() const { return m_Position; }
		inline const Maths::vec2& getSize() const { return m_Size; }
		inline const Maths::vec4& getColor() const { return m_Colour; };
		inline const std::vector<Maths::vec2>& getUVs() const { return m_UVS; }
	};
}