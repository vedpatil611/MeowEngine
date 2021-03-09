#include "MeowPCH.h"
#include "Application.h"

#include <functional>

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#define BIND_EVENT_FN(x) std::bind(x, this, std::placeholders::_1)

namespace Meow {
	Application::Application()
	{
		window = new Window("Meow", 800, 800);
		window->setEventCallback(BIND_EVENT_FN(&Application::onEvent));
	}

	Application::~Application()
	{
		SAFE_DELETE(window);
	}

	void Application::Run()
	{
	}

	static bool onkeypressed(KeyPressedEvent& e)
	{
		printf("key pressed\n");
		return true;
	}

	static bool onmousemoved(MouseMovedEvent& e)
	{
		printf("mouse moved\n");
		return true;
	}

	void Application::onEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<KeyPressedEvent>(onkeypressed);
		dispatcher.dispatch<MouseMovedEvent>(onmousemoved);
	}

}