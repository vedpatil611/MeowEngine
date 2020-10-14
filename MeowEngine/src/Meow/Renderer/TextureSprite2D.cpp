#include <MeowPCH.h>
#include "TextureSprite2D.h"
#include "Texture.h"

namespace Meow
{
	TextureSprite2D::TextureSprite2D(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour, const char* texturePath, Shader* shader)
		:Renderable2D(position, size, colour), m_Shader(shader), m_TexturePath(texturePath) 
	{ 
		
	}
	
	TextureSprite2D::~TextureSprite2D() { }

}