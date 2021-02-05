#include "MeowPCH.h"
#include "Sprite.h"

namespace Meow
{
	Sprite::Sprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour, Shader* shader, Texture* texture)
		:Renderable2D(position, size, colour), m_Shader(shader), m_Texture(texture)
	{
		m_TransformData.translation = position;
		float vertices[] =
		{
			0.0f - size.x / 2, 0.0f - size.y / 2, 0,
			0.0f - size.x / 2, 0.0f + size.y / 2, 0,
			0.0f + size.x / 2, 0.0f + size.y / 2, 0,
			0.0f + size.x / 2, 0.0f - size.y / 2, 0
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
			1.0f, 0.0f
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
		DELETE(m_IndexBuffer);
		DELETE(m_VertexArray);
	}

	void Sprite::addTranslation(Maths::vec3 translation)
	{
		m_TransformData.translation += translation;
	}

	void Sprite::addScaling(Maths::vec2 scale)
	{
		m_TransformData.scale += scale;
	}

	void Sprite::addRotation(float rotate)
	{
		m_TransformData.rotation += rotate;
	}

	void Sprite::setTranslation(Maths::vec3 translation)
	{
		m_TransformData.translation = translation;
	}

	void Sprite::setScaling(Maths::vec2 scale)
	{
		m_TransformData.scale = scale;
	}

	void Sprite::setRotation(float rotate)
	{
		m_TransformData.rotation = rotate;
	}

	void Sprite::updateUniforms(float delta) const
	{
		Maths::mat4 transforms(1.0f);
		transforms.translate(m_TransformData.translation).scale(m_TransformData.scale).rotateZ(m_TransformData.rotation);
		m_Shader->setUniformMat4f("u_model_mat", transforms);
		m_Shader->setUniform1i("u_Texture", 0);
	}
}