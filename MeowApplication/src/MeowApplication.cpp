#include "MeowApplication.h"


Meow::Application* Meow::CreateApplication()
{
	return new MeowApplication();
}

void MeowApplication::Run()
{
	Meow::Window window("Meow", 800, 600);
	while (!window.closed())
	{
		window.update();
	}
}
