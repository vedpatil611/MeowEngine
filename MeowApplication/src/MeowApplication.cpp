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