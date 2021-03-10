#pragma once

#include <Meow/Core.h>
#include <Meow/Events/Event.h>

namespace Meow 
{
	class MEOW_API Layer 
	{
	public:
		Layer() = default;
		~Layer() = default;

		virtual void onAttach();
		virtual void onUpdate();
		virtual void onDettach();
		virtual void onEvent(Event& e);
	};
}