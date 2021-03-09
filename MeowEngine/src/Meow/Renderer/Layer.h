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

		void onAttach();
		void onDettach();
		void onUpdate();
		void onEvent(Event& e);
	};
}