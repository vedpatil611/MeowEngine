#include "MeowPCH.h"
#include "MeowApplication.h"

#ifdef MEOW_PLATFORM_WINDOWS
#include <Windows.h>
#endif 

#include <ctime>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Renderer/BatchRenderer2D.h>
#include <Meow/Renderer/StaticSprite.h>
#include <Meow/Renderer/Shader.h>
#include <Meow/Utils/File.h>
#include <Meow/Utils/Timer.h>
#include <Meow.h>

Meow::Application* Meow::CreateApplication()
{
	/*#ifdef MEOW_PLATFORM_WINDOWS
		#ifndef DEBUG
			ShowWindow(GetConsoleWindow(), SW_HIDE);
		#else
			ShowWindow(GetConsoleWindow(), SW_SHOW);
		#endif 
	#endif */

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

	Meow::BatchRenderer2D renderer;

	Meow::Shader shader("shaders/renderable2d.vert.glsl", "shaders/renderable2d.frag.glsl");
	//Meow::Shader shader("shaders/mouse_lighting.vert.glsl", "shaders/mouse_lighting.frag.glsl");
	
	auto proj = Meow::Maths::mat4::orthographic(0, 100, 0, 100, -1, 1);
	shader.enable();
	shader.setUniformMat4f("u_proj_mat", proj);

	// Vector of square sprites for tile map
	std::vector<Meow::StaticSprite*> sprites;
	
	srand(static_cast<unsigned int>(time(NULL)));
	
	for (float y = 0; y < 100.0f; ++y)
	{
		for (float x = 0; x < 100.0f; ++x)
		{
			sprites.emplace_back(new Meow::StaticSprite(Meow::Maths::vec3(x, y, 0), Meow::Maths::vec2(0.9f, 0.9f), Meow::Maths::vec4(0.0f, rand() % 10 / 10.0f, 0.0f, 1.0f), &shader));
		}
	}
	
	shader.enable();
	Meow::Utils::Timer timer, t2;
	t2.reset();
	while (!window.closed())
	{
		window.update();

		timer.reset();
		renderer.begin();
		
		for (int i = 0; i < sprites.size(); ++i)
		{
			renderer.submit(sprites[i]);
		}
		//shader.setUniform2f("u_LightPos", Meow::Maths::vec2(static_cast<float>(window.getMouseX() / 8), static_cast<float>(window.getMouseY() / 8)));

		renderer.end();
		renderer.flush();
		
		//LOG << static_cast<int>(1 / timer.getElapsedTime()) << END_LOG;
	}
}