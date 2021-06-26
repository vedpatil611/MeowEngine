#include "MeowPCH.h"
#include "TileSprite.h"

namespace Meow
{
	TileSprite::TileSprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour, Shader* shader)
		:Renderable2D(position, size, colour), m_Shader(shader) { }

	TileSprite::TileSprite(const Maths::vec3& position, const Maths::vec2& size, Texture* texture, Shader* shader)
		:Renderable2D(position, size, {1.0f, 0.0f, 1.0f, 1.0f}), m_Shader(shader) 
	{ 
		m_Texture = texture;
	}

	TileSprite::~TileSprite() { }
}
