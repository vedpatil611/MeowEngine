#pragma once

#include <Meow/Core.h>
#include "Layer.h"
#include <vector>

namespace Meow 
{
	class MEOW_API LayerStack
	{
	private:
		std::vector<Rc<Layer>> m_Layer;
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Rc<Layer> layer);
		void popLayer();
		void popLayer(Rc<Layer> layer);

		inline std::vector<Rc<Layer>>::iterator begin() { return m_Layer.begin(); }
		inline std::vector<Rc<Layer>>::iterator end() { return m_Layer.end(); }
		inline std::vector<Rc<Layer>>::reverse_iterator rbegin() { return m_Layer.rbegin(); }
		inline std::vector<Rc<Layer>>::reverse_iterator rend() { return m_Layer.rend(); }
	};
}