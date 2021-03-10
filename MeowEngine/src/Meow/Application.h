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

		inline static Application* s_Instance = nullptr;
	public:
		Application();
		~Application();

		virtual void Run();

		void onEvent(Event& event);
		void pushLayer(Layer* layer);

		static inline Application& getApplication() { return *s_Instance; }
		inline Window* getWindow() { return window; }
	};

	Application* CreateApplication();
}
