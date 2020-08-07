#include "MeowApplication.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Window.h>
#include <iostream>
#include <sstream>
#include <fstream>

Meow::Application* Meow::CreateApplication()
{
	using namespace Meow::Maths;
	vec4 a;
	a += vec4(3.0f, 1.0f, 2.0f, 0.0f);
	a -= vec4(1.0f, 2.0f, 0.0f, 0.0f);
	vec4 b(3.0f, 2.0f, 1.0f, 0.0f);
	vec4 c = a + b;
	vec4 d = a.sub(b);
	a.x = 100.0f;
	std::cout << c << " " << d;

	
	return new MeowApplication();
}

void MeowApplication::Run()
{
	Meow::Window window("Meow", 800, 600);
	while (!window.closed())
	{
		window.update();
		std::cout << window.getWidth() << " " << window.getHeight() << std::endl;
	}
}