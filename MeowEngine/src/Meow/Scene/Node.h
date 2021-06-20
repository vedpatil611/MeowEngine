#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include <string>

DISABLE_WARNINGS()

namespace Meow::Scene
{
	class MEOW_API Node
	{
		Maths::vec2 m_Position = { 0.0f, 0.0f };
		Maths::vec2 m_Scale = { 1.0f, 1.0f };
		float m_Rotation = 0.0f;
		std::string m_Name = "";
		std::vector<Node*> m_Childs;
		class Shader* m_Shader = nullptr;
	public:
		Node() = default;

		void addChild(Node* node);
		inline std::vector<Node*>& getChildren() { return m_Childs; }

		virtual void update(float delta);
		virtual void render(float delta);
	};
}
