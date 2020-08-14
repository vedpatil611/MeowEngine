#include "MeowPCH.h"
#include "Renderable2D.h"

namespace Meow
{
	Renderable2D::Renderable2D(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour, Shader& shader)
		:m_Position(position), m_Size(size), m_Colour(colour), m_Shader(shader)
	{
		m_VertexArray = new VertexArray();
		float vertices[] =
		{
			0.0f  , 0.0f  , 0.0f,
			0.0f  , size.y, 0.0f,
			size.x, size.y, 0.0f,
			size.x, 0.0f  , 0.0f
		};
		float colours[] =
		{
			colour.x, colour.y, colour.z, colour.w,
			colour.x, colour.y, colour.z, colour.w,
			colour.x, colour.y, colour.z, colour.w,
			colour.x, colour.y, colour.z, colour.w
		};

		m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
		m_VertexArray->addBuffer(new Buffer(colours, 4 * 4, 4), 1);

		unsigned short indices[] = { 0, 1, 2, 2, 3, 0 };
		m_IndexBuffer = new IndexBuffer(indices, 6);
	}
	
	Renderable2D::~Renderable2D()
	{
		delete m_VertexArray;
		delete m_IndexBuffer;
	}

	void Renderable2D::translate(const Maths::vec3& translation)
	{
		m_Position += translation;
	}
}

