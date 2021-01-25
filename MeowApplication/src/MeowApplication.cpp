#include "MeowPCH.h"
#include "MeowApplication.h"

#define BATCH_TEST

#ifdef MEOW_PLATFORM_WINDOWS
#include <Windows.h>
#endif 

#include <ctime>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Renderer/Shader.h>
#include <Meow/Utils/File.h>
#include <Meow/Utils/Timer.h>
#include <Meow.h>

#include <Meow/Renderer/Texture.h>

#ifdef BATCH_TEST
#include <Meow/Renderer/BatchRenderer2D.h>
#include <Meow/Renderer/TileSprite.h>
#else
#include <Meow/Renderer/SimpleRenderer2D.h>
#include <Meow/Renderer/Sprite.h>
#endif // BATCH_TEST

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
	Application::Run();
	
	window->setVSyncEnable(false);
	window->setBackgrondColor({ 0.0f, 0.0f, 0.0f, 1.0f });

#ifdef BATCH_TEST
	Meow::BatchRenderer2D renderer;
#else
	Meow::SimpleRenderer2D renderer;
#endif

	std::vector<Meow::Renderable2D*> sprites;

	//Meow::Shader shader("shaders/texture2d.vert.glsl", "shaders/texture2d.frag.glsl");
	Meow::Shader shader("shaders/texture2d_defuse.vert.glsl", "shaders/texture2d_defuse.frag.glsl");
	//Meow::Shader shader("shaders/renderable2d.vert.glsl", "shaders/renderable2d.frag.glsl");
	//Meow::Shader shader("shaders/mouse_lighting.vert.glsl", "shaders/mouse_lighting.frag.glsl");
	
	auto proj = Meow::Maths::mat4::orthographic(-50, 50, -50, 50, -10, 10);
	//auto proj = Meow::Maths::mat4::perspective(110, 1.0f, -10, 10);
	Meow::Maths::mat4 model(1.0f);


	shader.enable();
	//view.translate({ 0.0f, 0.0f, 0.0f });
	shader.setUniformMat4f("u_proj_mat", proj);
	shader.setUniformMat4f("u_model_mat", model);
	//shader.setUniformMat4f("u_view_mat", view);
	//shader.setUniformMat4f("u_MVP", proj);

	// Vector of square sprites for tile map
	
	srand(static_cast<unsigned int>(time(NULL)));
	
	Meow::Texture texture("assets/Circle.png");
	texture.bind();
	shader.enable();
	shader.setUniform1i("u_Texture", 0);

	for (float y = -50; y < 50.0f; ++y)
	{
		for (float x = -50; x < 50.0f; ++x)
		{
#ifdef BATCH_TEST
			sprites.emplace_back(new Meow::TileSprite(Meow::Maths::vec3(x, y, 0), Meow::Maths::vec2(0.9f, 0.9f),
				Meow::Maths::vec4(0.0f, rand() % 10 / 10.0f, 0.0f, 1.0f), &shader));
#else
			sprites.emplace_back(new Meow::Sprite(Meow::Maths::vec3(x, y, 0), Meow::Maths::vec2(0.9f, 0.9f),
				Meow::Maths::vec4(0.0f, rand() % 10 / 10.0f, 0.0f, 1.0f), &shader));
#endif 
		}
	}
	
	shader.enable();
	Meow::Utils::Timer timer, t2;
	t2.reset();
	while (!window->closed())
	{
		window->update();

		timer.reset();
		renderer.begin();
		
		for (unsigned int i = 0; i < sprites.size(); ++i)
		{
			renderer.submit(sprites[i]);
		}

		model.rotateX(1.0f);
		shader.setUniformMat4f("u_model_mat", model);
		shader.setUniform2f("u_LightPos", Meow::Maths::vec2(static_cast<float>(window->getMouseX() / (window->getWidth() / 100) - 50), static_cast<float>(window->getMouseY() / (window->getHeight() / 100) - 50)));

		renderer.end();
		renderer.flush();

		if (t2.getElapsedTime() > 1000000)
		{
			t2.reset();
			printf("%d\n", static_cast<int>(1000000 / timer.getElapsedTime()));
		}
	}
}