#include "MeowPCH.h"

#include <Meow/Renderable/AnimatedSprite.h>

#include <Meow/Renderer/Shader.h>
#include <Meow/Renderer/SpriteSheet.h>

namespace Meow
{
	AnimatedSprite::AnimatedSprite(const Maths::vec3& position, const Maths::vec2& size, Rc<class Texture> texture, Rc<Shader> shader)
		:Sprite(position, size, texture, shader)
	{
		auto* tex = dynamic_cast<SpriteSheet*>(m_Texture.get());
		m_CurrentIndex = tex->getStartIndex();
	}

	AnimatedSprite::~AnimatedSprite()
	{
	}
	
	void AnimatedSprite::updateUniforms(float delta) const
	{
		auto* tex = static_cast<SpriteSheet*>(m_Texture.get());

		Sprite::updateUniforms(delta);
		int maxSpriteCount = tex->getSpriteCountX() * tex->getSpriteCountY();
		m_Shader->setUniform1i("spritesCountX", tex->getSpriteCountX());
		m_Shader->setUniform1i("spritesCountY", tex->getSpriteCountY());
		m_Shader->setUniform1i("currentIndex", m_CurrentIndex);

		float updateTime = 1 / tex->getFps();
		lastTime += delta;
		if (lastTime > updateTime)
		{
			m_CurrentIndex = (m_CurrentIndex + 1) % maxSpriteCount;
			lastTime = 0.0;
		}
	}
}
