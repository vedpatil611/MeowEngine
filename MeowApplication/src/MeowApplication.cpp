#include "MeowApplication.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Render/Renderer.h>
#include <Meow/Render/Shader.h>
#include <Meow/Utils/File.h>
#include <Meow/Window.h>
#include <Meow/Log.h>

#ifdef MEOW_PLATFORM_WINDOWS
#include <Windows.h>
#endif 


Meow::Application* Meow::CreateApplication()
{
	#ifdef MEOW_PLATFORM_WINDOWS
		#ifndef DEBUG
			ShowWindow(GetConsoleWindow(), SW_HIDE);
		#else
			ShowWindow(GetConsoleWindow(), SW_SHOW);
		#endif 
	#endif 

	return new MeowApplication();
}

MeowApplication::MeowApplication()
{
}

MeowApplication::~MeowApplication()
{
}

void MeowApplication::Run()
{
	Meow::Window window("Meow", 800, 600);
	Meow::Maths::vec2 a;
	Meow::Maths::vec2 b(3.0f, 2.0f);

	Meow::Renderer* renderer = new Meow::Renderer(window);
	Meow::Shader* shader = new Meow::Shader("shaders/vert.glsl", "shaders/frag.glsl");
	shader->enable();
	renderer->testDraw(*shader);
	while (!window.closed())
	{
		renderer->testRender();
		window.update();
	}

	delete renderer;
	delete shader;
}