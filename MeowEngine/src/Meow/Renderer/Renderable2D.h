#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Renderer/IndexBuffer.h>
#include <Meow/Renderer/VertexArray.h>
#include <Meow/Renderer/Shader.h>

namespace Meow 
{ 
	class MEOW_API Renderable2D
	{
	private:
		Maths::vec3 m_Position;
		Maths::vec2 m_Size;
		Maths::vec4 m_Colour;

		const Shader& m_Shader;
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
	public:
		Renderable2D(Maths::vec3 postion, Maths::vec2 size, Maths::vec4 colour, const Shader& shader);
		~Renderable2D();

		inline const VertexArray* getVAO() const { return m_VertexArray; }
		inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
		inline const Shader& getShader() const { return m_Shader; }

		inline const Maths::vec3& getPositions() const { return m_Position; }
		inline const Maths::vec2& getSize() const { return m_Size; }
		inline const Maths::vec4& getColour() const { return m_Colour; }
	};
}