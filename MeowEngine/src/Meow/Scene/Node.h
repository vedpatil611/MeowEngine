#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include <string>

namespace Meow
{
	class MEOW_API Node
	{
		Maths::vec2 m_Position = { 0.0f, 0.0f };
		Maths::vec2 m_Scale = { 1.0f, 1.0f };
		float m_Rotation = 0.0f;
		std::string m_Name = "";
		std::vector<Node*> m_Childs;
	public:
		Node() = default;

		void addChildren(Node* node);

		virtual void update(float delta) = 0;
	};
}