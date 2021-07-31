#include "MeowPCH.h"
#include "Renderable2D.h"

namespace Meow
{
	Renderable2D::Renderable2D(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour)
		:m_Position(position), m_Size(size), m_Colour(colour) 
	{
		m_UVS.emplace_back(0.0f, 0.0f);
		m_UVS.emplace_back(0.0f, 1.0f);
		m_UVS.emplace_back(1.0f, 1.0f);
		m_UVS.emplace_back(1.0f, 0.0f);
	}
	
	Renderable2D::~Renderable2D() { }
}

