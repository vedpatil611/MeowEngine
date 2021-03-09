#pragma once

#include <Meow/Core.h>
#include "Layer.h"
#include <vector>

namespace Meow 
{
	class MEOW_API LayerStack
	{
	private:
		std::vector<Layer*> m_Layer;
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Layer* layer);
		void popLayer();
		void popLayer(Layer* layer);

		inline std::vector<Layer*>::iterator begin() { return m_Layer.begin(); }
		inline std::vector<Layer*>::iterator end() { return m_Layer.end(); }
		inline std::vector<Layer*>::reverse_iterator rbegin() { return m_Layer.rbegin(); }
		inline std::vector<Layer*>::reverse_iterator rend() { return m_Layer.rend(); }
	};
}