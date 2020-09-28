#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace Meow 
{ 

	struct VertexData {
		Maths::vec3 vertex;
		Maths::vec4 colour;
	};

	class MEOW_API Renderable2D
	{
	protected:
		Maths::vec3 m_Position;
		Maths::vec2 m_Size;
	public:
		Renderable2D(const Maths::vec3& position, const Maths::vec2& size);
		virtual ~Renderable2D();

		virtual inline const VertexArray* getVAO() const = 0;
		virtual inline const IndexBuffer* getIBO() const = 0;
		virtual inline Shader* getShader() const = 0;

		inline const Maths::vec3& getPositions() const { return m_Position; }
		inline const Maths::vec2& getSize() const { return m_Size; }
		virtual inline const Maths::vec4& getColor() const = 0;
	};
}