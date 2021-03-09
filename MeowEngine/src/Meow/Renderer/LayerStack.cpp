#include "MeowPCH.h"
#include "LayerStack.h"

namespace Meow
{
	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layer)
			delete layer;
	}

	void LayerStack::pushLayer(Layer* layer)
	{
		m_Layer.emplace_back(layer);
	}

	void LayerStack::popLayer()
	{
		m_Layer.pop_back();
	}

	void LayerStack::popLayer(Layer* layer)
	{
		auto it = std::find(m_Layer.begin(), m_Layer.end(), layer);
		if (it != m_Layer.end())
		{
			m_Layer.erase(it);
		}
	}
}
