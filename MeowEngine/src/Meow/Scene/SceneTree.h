#pragma once

#include <Meow/Core.h>
#include <vector>

class MEOW_API SceneTree {
private:
	std::vector<class Node*> m_Nodes;
public:
	SceneTree() {}

	void addItem(class Node* node);
};