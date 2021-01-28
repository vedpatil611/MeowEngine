#include "MeowPCH.h"
#include "AnimatedSprite.h"

namespace Meow
{
	AnimatedSprite::AnimatedSprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour, Shader* shader, Texture* texture, int spriteCountX, int spriteCountY, float fps)
		:Sprite(position, size, colour, shader, texture), m_fps(fps), m_SpriteCountX(spriteCountX), m_SpriteCountY(spriteCountY)
	{
		
	}

	AnimatedSprite::~AnimatedSprite()
	{
	}

	void AnimatedSprite::updateUniforms() const
	{
		Sprite::updateUniforms();
		static int spriteIndex = 0;
		int maxSpriteCount = m_SpriteCountX * m_SpriteCountY;
		m_Shader->setUniform1i("spritesCountX", m_SpriteCountX);
		m_Shader->setUniform1i("spritesCountY", m_SpriteCountY);
		m_Shader->setUniform1i("currentIndex", spriteIndex);

		spriteIndex = (spriteIndex + 1) % maxSpriteCount;
	}
}