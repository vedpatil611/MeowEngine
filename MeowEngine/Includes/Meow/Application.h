#pragma once

#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Renderer/LayerStack.h"
#include <functional>

using KeyPressedFn			= std::function<bool(Meow::KeyPressedEvent&)>;
using KeyReleasedFn			= std::function<bool(Meow::KeyReleasedEvent&)>;
using KeyTypedFn			= std::function<bool(Meow::KeyTypedEvent&)>;
using WindowResizedFn		= std::function<bool(Meow::WindowResizeEvent&)>;
using WindowClosedFn		= std::function<bool(Meow::WindowCloseEvent&)>;
using AppTickFn				= std::function<bool(Meow::AppTickEvent&)>;
using AppUpdateFn			= std::function<bool(Meow::AppUpdateEvent&)>;
using AppRenderFn			= std::function<bool(Meow::AppRenderEvent&)>;
using MouseButtonPressedFn	= std::function<bool(Meow::MouseButtonPressedEvent&)>;
using MouseButtonReleasedFn	= std::function<bool(Meow::MouseButtonReleasedEvent&)>;
using MouseMovedFn			= std::function<bool(Meow::MouseMovedEvent&)>;
using MouseScrolledFn		= std::function<bool(Meow::MouseScrolledEvent&)>;

#define BIND_FN(x) std::bind(&x, this, std::placeholders::_1)

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

		void setKeyPressedCallback(const KeyPressedFn& keyPressedFn);
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
