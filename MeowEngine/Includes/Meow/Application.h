#pragma once

#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Renderer/LayerStack.h"

using KeyPressedFn			= bool (*)(class Meow::KeyPressedEvent&);
using KeyReleasedFn			= bool (*)(class Meow::KeyReleasedEvent&);
using KeyTypedFn			= bool (*)(class Meow::KeyTypedEvent&);
using WindowResizedFn		= bool (*)(class Meow::WindowResizeEvent&);
using WindowClosedFn		= bool (*)(class Meow::WindowCloseEvent&);
using AppTickFn				= bool (*)(class Meow::AppTickEvent&);
using AppUpdateFn			= bool (*)(class Meow::AppUpdateEvent&);
using AppRenderFn			= bool (*)(class Meow::AppRenderEvent&);
using MouseButtonPressedFn	= bool (*)(class Meow::MouseButtonPressedEvent&);
using MouseButtonReleasedFn	= bool (*)(class Meow::MouseButtonReleasedEvent&);
using MouseMovedFn			= bool (*)(class Meow::MouseMovedEvent&);
using MouseScrolledFn		= bool (*)(class Meow::MouseScrolledEvent&);

namespace Meow {
	class MEOW_API Application
	{
	protected:
		Rc<Window> window;
		LayerStack m_LayerStack;
		Rc<class Layer> m_BaseLayer;
		inline static Application* s_Instance = nullptr;

		KeyPressedFn m_KeyPressedFn = nullptr;
		KeyReleasedFn m_KeYReleasedFn = nullptr;
		KeyTypedFn m_KeyTypedFn = nullptr;
		WindowResizedFn m_WindowResizedFn = nullptr;
		WindowClosedFn m_WindowClosedFn = nullptr;
		AppTickFn m_AppTickFn = nullptr;
		AppUpdateFn m_AppUpdateFn = nullptr;
		AppRenderFn m_AppRenderFn = nullptr;
		MouseButtonPressedFn m_MousePressedFn = nullptr;
		MouseButtonReleasedFn m_MouseReleasedFn = nullptr;
		MouseMovedFn m_MouseMovedfn = nullptr;
		MouseScrolledFn m_MouseScrolledFn = nullptr;
	public:
		Application();
		virtual ~Application();

		virtual void Run();

		void onEvent(Event& event);
		void pushLayer(Rc<class Layer> layer);

		void setKeyPressedCallback(KeyPressedFn keyPressedFn);
		void setKeyReleasedCallback(const KeyReleasedFn& keyReleasedFn);
		void setKeyTypedCallback(const KeyTypedFn& keyTypedFn);
		void setWindowResizedCallback(const WindowResizedFn& windowResizedFn);
		void setWindowClosedCallback(const WindowClosedFn& windowClosedFn);
		void setAppTickCallback(const AppTickFn& apptickFn);
		void setAppUpdateCallback(const AppUpdateFn& appUpdateFn);
		void setAppRenderCallback(const AppRenderFn& appRenderFn);
		void setMouseButtonPressedCallback(const MouseButtonPressedFn& mousePressedFn);
		void setMouseButtonReleasedCallback(const MouseButtonReleasedFn& mouseReleasedFn);
		void setMouseMovedCallback(const MouseMovedFn& mouseMovedFn);
		void serMouseScrolledFn(const MouseScrolledFn& mouseScrolledFn);

		static inline Application& getApplication() { return *s_Instance; }
		inline Rc<Window> getWindow() { return window; }
		inline Rc<class Layer> getBaseLayer() { return m_BaseLayer; };
	};

	Application* CreateApplication();
}
