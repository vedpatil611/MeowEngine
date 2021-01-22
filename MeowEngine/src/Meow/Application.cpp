#include "MeowPCH.h"
#include "Application.h"
#include <functional>
namespace Meow {
	Application::Application()
	{
		window = new Window("Meow", 800, 800);
		//window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
		//window->setEventCallback(Application::onEvent);
	}

	Application::~Application()
	{
		delete window;
	}

	void Application::Run()
	{
	}

	void Application::onEvent(Event& event)
	{
	}
}