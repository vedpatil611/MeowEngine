#include "MeowPCH.h"
#include "Sprite.h"

namespace Meow
{
	Sprite::Sprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour, Shader* shader)
		:Renderable2D(position, size, colour), m_Shader(shader)
	{
		float vertices[] =
		{
			position.x			, position.y			, position.z,
			position.x			, position.y + size.y	, position.z,
			position.x + size.x	, position.y + size.y	, position.z,
			position.x + size.x	, position.y			, position.z
		};
		float colours[] =
		{
			colour.r, colour.g, colour.b, colour.a,
			colour.r, colour.g, colour.b, colour.a,
			colour.r, colour.g, colour.b, colour.a,
			colour.r, colour.g, colour.b, colour.a
		};
		float uv[] =
		{
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f,
		};
		m_VertexArray = new VertexArray();
		m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
		m_VertexArray->addBuffer(new Buffer(colours, 4 * 4, 4), 1);
		m_VertexArray->addBuffer(new Buffer(uv, 4 * 2, 2), 2);

		unsigned short indices[] = { 0, 1, 2, 2, 3, 0 };
		m_IndexBuffer = new IndexBuffer(indices, 6);
	}
	Sprite::~Sprite()
	{
		delete m_IndexBuffer;
		delete m_VertexArray;
	}
}