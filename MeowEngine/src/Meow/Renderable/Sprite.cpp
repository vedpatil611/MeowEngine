#include "MeowPCH.h"
#include <Meow/Renderable/Sprite.h>

#include <Meow/Renderer/Buffer.h>
#include <Meow/Renderer/IndexBuffer.h>
#include <Meow/Renderer/Shader.h>
#include <Meow/Renderer/VertexArray.h>

namespace Meow
{
	Sprite::Sprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour, Shader* shader)
		:Renderable2D(position, size, colour), m_Shader(shader) {  }

	Sprite::Sprite(const Maths::vec3& position, const Maths::vec2& size, Texture* tex, Shader* shader)
		:Renderable2D(position, size, {1.0f, 0.0f, 1.0f, 1.0f}), m_Shader(shader) 
	{
		m_Texture = tex;
	}

	Sprite::~Sprite() {}

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
