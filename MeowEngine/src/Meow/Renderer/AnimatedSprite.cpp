#include "MeowPCH.h"
#include "AnimatedSprite.h"

namespace Meow
{
	AnimatedSprite::AnimatedSprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour, Shader* shader, Texture* texture, int spriteCountX, int spriteCountY, int startIndex, float fps)
		:Sprite(position, size, colour, shader, texture), m_fps(fps), m_SpriteCountX(spriteCountX), m_SpriteCountY(spriteCountY), m_StartIndex(startIndex)
	{
		
	}

	AnimatedSprite::~AnimatedSprite()
	{
	}

	void AnimatedSprite::updateUniforms(float delta)
	{
		Sprite::updateUniforms(delta);
		int maxSpriteCount = m_SpriteCountX * m_SpriteCountY;
		m_Shader->setUniform1i("spritesCountX", m_SpriteCountX);
		m_Shader->setUniform1i("spritesCountY", m_SpriteCountY);
		m_Shader->setUniform1i("currentIndex", m_StartIndex);

		float updateTime = 1 / m_fps;
		lastTime += delta;
		if (lastTime > updateTime)
		{
			m_StartIndex = (m_StartIndex + 1) % maxSpriteCount;
			lastTime = 0.0;
		}
	}
}