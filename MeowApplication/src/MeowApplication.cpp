#include "MeowApplication.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Window.h>
#include <Meow/Log.h>
#include <iostream>
#include <sstream>
#include <vector>

Meow::Application* Meow::CreateApplication()
{
	

	return new MeowApplication();
}

void MeowApplication::Run()
{
	using namespace Meow;
	Meow::Window window("Meow", 800, 600);
	Meow::Maths::vec2 a;
	Meow::Maths::vec2 b(3.0f, 2.0f);

	Meow::Log::log("Log value for fun {}  {}", {&a, &b});
	Meow::Log::warn("warning 0 vector {}", {&a});
	Meow::Log::error("0 vector not allowed {}", {&a});
	
	while (!window.closed())
	{
		window.update();
	}
}