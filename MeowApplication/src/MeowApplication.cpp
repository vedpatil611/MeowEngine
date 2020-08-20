#include "MeowPCH.h"
#include "MeowApplication.h"

#include <ctime>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Renderer/BatchRenderer2D.h>
#include <Meow/Renderer/SimpleRenderer2D.h>
#include <Meow/Renderer/StaticSprite.h>
#include <Meow/Renderer/Shader.h>
#include <Meow/Utils/File.h>
#include <Meow.h>
#ifdef MEOW_PLATFORM_WINDOWS
#include <Windows.h>
#endif 

#define BATCH_RENDER 1

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
	Meow::Window window("Meow", 800, 800);

#if BATCH_RENDER
	Meow::BatchRenderer2D renderer;
#else
	Meow::SimpleRenderer2D renderer;
#endif 

	Meow::Shader shader("shaders/mouse_lighting.vert.glsl", "shaders/mouse_lighting.frag.glsl");
	
	Meow::Maths::mat4 proj = Meow::Maths::mat4::orthographic(0, 100, 0, 100, -1, 1);
	shader.enable();
	shader.setUniformMat4f("u_proj_mat", proj);

	std::vector<Meow::StaticSprite*> sprites;
	
	srand(time(NULL));
	
	for (float y = 0; y < 100.0f; ++y)
	{
		for (float x = 0; x < 100.0f; ++x)
		{
			sprites.emplace_back(new Meow::StaticSprite(Meow::Maths::vec3(x, y, 0), Meow::Maths::vec2(0.9f, 0.9f), Meow::Maths::vec4(rand() % 10 / 10.0f, 0.7f, 0.0f, 1.0f), &shader));
		}
	}

	//Meow::StaticSprite testObj1(Meow::Maths::vec3(200.0f, 200.0f, 0.0f), Meow::Maths::vec2(100.0f, 100.0f), Meow::Maths::vec4(1.0f, 0.0f, 0.0f, 1.0f), &shader);
	//Meow::StaticSprite testObj2(Meow::Maths::vec3(500.0f, 300.0f, 0.0f), Meow::Maths::vec2(200.0f, 300.0f), Meow::Maths::vec4(0.0f, 0.0f, 1.0f, 1.0f), &shader);
	shader.enable();
	while (!window.closed())
	{
		window.update();
#if BATCH_RENDER
		renderer.begin();
#endif
		for (int i = 0; i < sprites.size(); ++i)
		{
			renderer.submit(sprites[i]);
		}
		shader.setUniform2f("u_LightPos", Meow::Maths::vec2(window.getMouseX() / 8, window.getMouseY() / 8));
		//renderer.submit(&testObj1);
		//renderer.submit(&testObj2);
#if BATCH_RENDER
		renderer.end();
#endif
		renderer.flush();
	}
}