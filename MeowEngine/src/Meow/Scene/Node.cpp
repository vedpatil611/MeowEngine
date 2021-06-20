#include "MeowPCH.h"
#include "Node.h"

namespace Meow::Scene {
	void Node::addChild(Node* node)
	{
		m_Childs.push_back(node);
	}

	void Node::update(float delta) {}
	void Node::render(float delta) {}
}

