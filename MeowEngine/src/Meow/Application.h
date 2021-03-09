#pragma once

#include "Window.h"
#include "Events/Event.h"
#include "Renderer/LayerStack.h"

namespace Meow {
	class MEOW_API Application
	{
	protected:
		Window* window;
		LayerStack m_LayerStack;
	public:
		Application();
		~Application();

		virtual void Run();

		void onEvent(Event& event);

		inline Window* getWindow() { return window; }
	};

	Application* CreateApplication();
}
