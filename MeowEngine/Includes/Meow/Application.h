#pragma once

#include "Window.h"
#include "Events/Event.h"
#include "Renderer/LayerStack.h"

namespace Meow {
	class MEOW_API Application
	{
	protected:
		Rc<Window> window;
		LayerStack m_LayerStack;
		class Layer* m_BaseLayer;
		inline static Application* s_Instance = nullptr;
	public:
		Application();
		virtual ~Application();

		virtual void Run();

		void onEvent(Event& event);
		void pushLayer(class Layer* layer);

		static inline Application& getApplication() { return *s_Instance; }
		inline Rc<Window> getWindow() { return window; }
		inline class Layer* getBaseLayer() { return m_BaseLayer; };
	};

	Application* CreateApplication();
}
