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

		m_BaseLayer = new Layer();
		pushLayer(m_BaseLayer);
	}

	Application::~Application()
	{
		for (auto layer : m_LayerStack)
		{
			layer->onDettach();
		}

		if(s_Instance == this) s_Instance = nullptr;
	}

	void Application::Run()
	{

	}

	static bool onkeypressed(KeyPressedEvent& e)
	{
		return true;
	}

	static bool onmousemoved(MouseMovedEvent& e)
	{
		return true;
	}

	static bool onWindowResize(WindowResizeEvent& e)
	{
		return true;
	}

	void Application::onEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<KeyPressedEvent>(onkeypressed);
		dispatcher.dispatch<MouseMovedEvent>(onmousemoved);
		dispatcher.dispatch<WindowResizeEvent>(onWindowResize);

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); )
		{
			(*it++)->onEvent(event);
			if (event.handled) break;
		}
	}

	void Application::pushLayer(Layer* layer)
	{
		m_LayerStack.pushLayer(layer);
		layer->onAttach();
	}
}
