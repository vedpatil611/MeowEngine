#include "MeowPCH.h"
#include "Layer.h"

namespace Meow 
{
	void Layer::onAttach()
	{
	}
	void Layer::onDettach()
	{
	}
	void Layer::onUpdate()
	{
	}
	void Layer::onEvent(Event& e)
	{
	}
	void Layer::begin()
	{
	}
	void Layer::submit(const std::vector<Renderable2D*>& sprites)
	{
		renderer.begin();
		for(auto sprite: sprites)
			renderer.submit(sprite);
		renderer.end();
	}
	void Layer::onRender(float delta)
	{
		renderer.flush(delta);
	}
	void Layer::end()
	{
	}
}
