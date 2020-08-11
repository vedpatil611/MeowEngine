#include "MeowApplication.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Utils/File.h>
#include <Meow/Window.h>
#include <Meow/Log.h>
#include <iostream>
#include <sstream>
#include <vector>

#ifdef MEOW_PLATFORM_WINDOWS
#include <Windows.h>
#endif 


Meow::Application* Meow::CreateApplication()
{
	#ifdef MEOW_PLATFORM_WINDOWS
		#ifndef DEBUG
			ShowWindow(GetConsoleWindow(), SW_HIDE);
		#endif 
	#endif 

	return new MeowApplication();
}

void MeowApplication::Run()
{
	using namespace Meow;
	Meow::Window window("Meow", 800, 600);
	Meow::Maths::vec2 a;
	Meow::Maths::vec2 b(3.0f, 2.0f);

	while (!window.closed())
	{
		window.update();
	}
}