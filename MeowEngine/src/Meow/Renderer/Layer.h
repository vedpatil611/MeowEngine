#pragma once

#include <Meow/Core.h>
#include <Meow/Events/Event.h>
#include <Meow/Renderer/BatchRenderer2D.h>
#include <Meow/Renderer/Renderable2D.h>
#include <vector>

namespace Meow 
{
	class MEOW_API Layer 
	{
	protected: 
		BatchRenderer2D renderer;
	public:
		Layer() = default;
		~Layer() = default;

		virtual void onAttach();
		virtual void onUpdate();
		virtual void onDettach();
		virtual void onEvent(Event& e);

		virtual void begin();
		virtual void submit(const std::vector<Renderable2D*>& sprites);
		virtual void onRender(float delta);
		virtual void end();
	};
}