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
		Layer* m_BaseLayer;
		inline static Application* s_Instance = nullptr;
	public:
		Application();
		virtual ~Application();

		virtual void Run();

		void onEvent(Event& event);
		void pushLayer(Layer* layer);

		static inline Application& getApplication() { return *s_Instance; }
		inline Window* getWindow() { return window; }
		inline Layer* getBaseLayer() { return m_BaseLayer; };
	};

	Application* CreateApplication();
}
