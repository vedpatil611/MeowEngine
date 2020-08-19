#include "MeowPCH.h"
#include "Renderable2D.h"

namespace Meow
{
	Renderable2D::Renderable2D(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour)
		:m_Position(position), m_Size(size), m_Colour(colour) { }
	
	Renderable2D::~Renderable2D() { }
}

