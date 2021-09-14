#pragma once

#include "Window.h"
#include "Events/Event.h"
#include "Renderer/LayerStack.h"

using KeyPressedFn			= bool (*)(class KeyPressedEvent&);
using KeyReleasedFn			= bool (*)(class KeyReleasedEvent&);
using KeyTypedFn			= bool (*)(class KeyTypedEvent&);
using WindowResizedFn		= bool (*)(class WindowResizeEvent&);
using WindowClosedFn		= bool (*)(class WindowCloseEvent&);
using AppTickFn				= bool (*)(class AppTickEvent&);
using AppUpdateFn			= bool (*)(class AppUpdateEvent&);
using AppRenderFn			= bool (*)(class AppRenderEvent&);
using MouseButtonPressedFn	= bool (*)(class MouseButtonPressedEvent&);
using MouseButtonReleasedFn	= bool (*)(class MouseButtonReleasedEvent&);
using MouseMovedFn			= bool (*)(class MouseMovedEvent&);
using MouseScrolledFn		= bool (*)(class MouseScrolledEvent&);

namespace Meow {
	class MEOW_API Application
	{
	protected:
		Rc<Window> window;
		LayerStack m_LayerStack;
		Rc<class Layer> m_BaseLayer;
		inline static Application* s_Instance = nullptr;
	public:
		Application();
		virtual ~Application();

		virtual void Run();

		void onEvent(Event& event);
		void pushLayer(Rc<class Layer> layer);

		static inline Application& getApplication() { return *s_Instance; }
		inline Rc<Window> getWindow() { return window; }
		inline Rc<class Layer> getBaseLayer() { return m_BaseLayer; };
	};

	Application* CreateApplication();
}
