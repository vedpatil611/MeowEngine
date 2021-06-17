#include "MeowPCH.h"
#include "Node.h"

void Meow::Node::addChildren(Node* node)
{
	m_Childs.push_back(node);
}
