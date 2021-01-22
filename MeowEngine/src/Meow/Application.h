#pragma once

#include "Window.h"
#include "Events/Event.h"

namespace Meow {
	class MEOW_API Application
	{
	protected:
		Window* window;
	public:
		Application();
		~Application();

		virtual void Run();

		void onEvent(Event& event);
		inline Window* getWindow() { return window; }
	};

	Application* CreateApplication();
}
