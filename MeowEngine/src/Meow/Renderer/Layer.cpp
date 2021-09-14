#include "MeowPCH.h"
#include <Meow/Renderer/Layer.h>

namespace Meow 
{
	void Layer::onAttach() {}
	
	void Layer::onDettach() {}
	
	void Layer::onUpdate() {}
	
	void Layer::onEvent(Event& e) {}
	
	void Layer::begin() {}
	
	void Layer::submit(Rc<Renderable2D> sprite)
	{
		m_Renderer.begin();
		m_Renderer.submit(sprite);
		m_Renderer.end();
	}
	
	void Layer::submit(const std::vector<Rc<Renderable2D>>& sprites)
	{
		m_Renderer.begin();
		for(auto sprite: sprites)
			m_Renderer.submit(sprite);
		m_Renderer.end();
	}

	void Layer::clear()
	{
		m_Renderer.clear();
	}
	
	void Layer::onRender(float delta)
	{
		m_Renderer.flush(delta);
	}
	
	void Layer::end() {}
}
