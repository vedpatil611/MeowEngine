#include <MeowPCH.h>
#include "Texture2D.h"

namespace Meow
{
	Texture2D::Texture2D(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour, const char* texturePath, Shader* shader)
		:Renderable2D(position, size, colour), m_Shader(shader), m_TexturePath(texturePath) 
	{ 
		
	}
	
	Texture2D::~Texture2D() { }

}