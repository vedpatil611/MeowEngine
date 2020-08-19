#include "MeowPCH.h"
#include "MeowApplication.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Renderer/SimpleRenderer2D.h>
#include <Meow/Renderer/StaticSprite.h>
#include <Meow/Renderer/Shader.h>
#include <Meow/Utils/File.h>
#include <Meow.h>
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
	Meow::Window window("Meow", 800, 800);

	Meow::SimpleRenderer2D renderer;
	Meow::Shader shader("shaders/renderable2d.vert.glsl", "shaders/renderable2d.frag.glsl");
	
	Meow::Maths::mat4 proj = Meow::Maths::mat4::orthographic(0, 800, 0, 800, -1, 1);
	shader.enable();
	shader.setUniformMat4f("u_proj_mat", proj);

	Meow::StaticSprite testObj(Meow::Maths::vec3(200.0f, 200.0f, 0.0f), Meow::Maths::vec2(100.0f, 100.0f), Meow::Maths::vec4(1.0f, 0.0f, 0.0f, 1.0f), &shader);
	//Meow::StaticSprite testObj2(Meow::Maths::vec3(500.0f, 300.0f, 0.0f), Meow::Maths::vec2(200.0f, 300.0f), Meow::Maths::vec4(0.0f, 0.0f, 1.0f, 1.0f), &shader);
	shader.enable();
	while (!window.closed())
	{
		window.update();
		//renderer.begin();
		renderer.submit(&testObj);
		//shader.setUniformMat4f("u_model_mat", Meow::Maths::mat4::translation(Meow::Maths::vec3(200.0f, 200.0f, 0.0f)));
		//renderer.submit(&testObj2);
		renderer.flush();
		//renderer.end();
	}
}