#include "MeowPCH.h"
#include "Level.h"

namespace Meow 
{
	Level::Level(const char* levelName)
		:m_LevelName(levelName) {}

	void Level::update(float delta)
	{
		iterateChildren(m_Root, delta, &Scene::Node::update);
	}

	void Level::render(float delta)
	{
		iterateChildren(m_Root, delta, &Scene::Node::render);
	}

	void Level::iterateChildren(Scene::Node* node, float delta, NodeIteratorFunctionvf fn)
	{
		for(auto x: node->getChildren())
		{
			(node->*fn)(delta);
			iterateChildren(x, delta, fn);
		}
	}
}
