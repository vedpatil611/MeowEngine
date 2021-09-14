#include "MeowPCH.h"
#include <Meow/Application.h>

#include <functional>

#include <Meow/Events/ApplicationEvent.h>
#include <Meow/Events/KeyEvent.h>
#include <Meow/Events/MouseEvent.h>

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace Meow {
	Application::Application()
	{
		ASSERT(!s_Instance);
		s_Instance = this;

		window = Rc<Window>(new Window("Meow", 800, 800));
		window->setEventCallback(BIND_EVENT_FN(Application::onEvent));

		m_BaseLayer = Rc<Layer>(new Layer());
		pushLayer(m_BaseLayer);
	}

	Application::~Application()
	{
		for (auto& layer : m_LayerStack)
		{
			layer->onDettach();
		}

		if(s_Instance == this) s_Instance = nullptr;
	}

	void Application::Run()
	{

	}

	void Application::onEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<KeyPressedEvent>(m_KeyPressedFn);
		dispatcher.dispatch<KeyReleasedEvent>(m_KeYReleasedFn);
		dispatcher.dispatch<KeyTypedEvent>(m_KeyTypedFn);
		dispatcher.dispatch<WindowResizeEvent>(m_WindowResizedFn);
		dispatcher.dispatch<WindowCloseEvent>(m_WindowClosedFn);
		dispatcher.dispatch<AppTickEvent>(m_AppTickFn);
		dispatcher.dispatch<AppRenderEvent>(m_AppRenderFn);
		dispatcher.dispatch<AppUpdateEvent>(m_AppUpdateFn);
		dispatcher.dispatch<MouseButtonPressedEvent>(m_MousePressedFn);
		dispatcher.dispatch<MouseButtonReleasedEvent>(m_MouseReleasedFn);
		dispatcher.dispatch<MouseMovedEvent>(m_MouseMovedfn);
		dispatcher.dispatch<MouseScrolledEvent>(m_MouseScrolledFn);

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); )
		{
			(*it++)->onEvent(event);
			if (event.handled) break;
		}
	}

	void Application::pushLayer(Rc<Layer> layer)
	{
		m_LayerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::setKeyPressedCallback(KeyPressedFn keyPressedFn)
	{
		m_KeyPressedFn = keyPressedFn;
	}

	void Application::setKeyReleasedCallback(const KeyReleasedFn& keyReleasedFn)
	{
		m_KeYReleasedFn = keyReleasedFn;
	}

	void Application::setKeyTypedCallback(const KeyTypedFn& keyTypedFn)
	{
		m_KeyTypedFn = keyTypedFn;
	}

	void Application::setWindowResizedCallback(const WindowResizedFn& windowResizedFn)
	{
		m_WindowResizedFn = windowResizedFn;
	}

	void Application::setWindowClosedCallback(const WindowClosedFn& windowClosedFn)
	{
		m_WindowClosedFn = windowClosedFn;
	}

	void Application::setAppTickCallback(const AppTickFn& apptickFn)
	{
		m_AppTickFn = apptickFn;
	}

	void Application::setAppUpdateCallback(const AppUpdateFn& appUpdateFn)
	{
		m_AppUpdateFn = appUpdateFn;
	}

	void Application::setAppRenderCallback(const AppRenderFn& appRenderFn)
	{
		m_AppRenderFn = appRenderFn;
	}

	void Application::setMouseButtonPressedCallback(const MouseButtonPressedFn& mousePressedFn)
	{
		m_MousePressedFn = mousePressedFn;
	}

	void Application::setMouseButtonReleasedCallback(const MouseButtonReleasedFn& mouseReleasedFn)
	{
		m_MouseReleasedFn = mouseReleasedFn;
	}

	void Application::setMouseMovedCallback(const MouseMovedFn& mouseMovedFn)
	{
		m_MouseMovedfn = mouseMovedFn;
	}

	void Application::serMouseScrolledFn(const MouseScrolledFn& mouseScrolledFn)
	{
		m_MouseScrolledFn = mouseScrolledFn;
	}
}
