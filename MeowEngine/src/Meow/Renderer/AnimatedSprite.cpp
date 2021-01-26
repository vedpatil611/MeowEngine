#include "MeowPCH.h"
#include "AnimatedSprite.h"

namespace Meow
{
	AnimatedSprite::AnimatedSprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour, Shader* shader, Texture* texture, float fps)
		:Sprite(position, size, colour, shader, texture), fps(fps)
	{
		
	}

	AnimatedSprite::~AnimatedSprite()
	{
	}
}