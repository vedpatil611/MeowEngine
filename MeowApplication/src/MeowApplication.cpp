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
#include <Meow/Renderer/SpriteSheet.h>

#ifdef BATCH_TEST
#include <Meow/Renderer/BatchRenderer2D.h>
#include <Meow/Renderer/TileSprite.h>
#else
#include <Meow/Renderer/SimpleRenderer2D.h>
#include <Meow/Renderer/Sprite.h>
#include <Meow/Renderer/AnimatedSprite.h>
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

	Meow::Shader shader("shaders/texture2d.vert.glsl", "shaders/texture2d.frag.glsl");
	Meow::Shader animatedSpriteShader("shaders/animated_sprites.vert.glsl", "shaders/animated_sprites.frag.glsl");

	auto proj = Meow::Maths::mat4::orthographic(-50, 50, -50, 50, -10, 10);
	Meow::Maths::mat4 model(1.0f);

	shader.enable();
	shader.setUniformMat4f("u_proj_mat", proj);

	//animatedSpriteShader.enable();
	//animatedSpriteShader.setUniformMat4f("u_proj_mat", proj);
	//shader.setUniformMat4f("u_view_mat", view);

	Meow::Texture texture("assets/Circle.png");
	//Meow::SpriteSheet animatedSprite("assets/Run.png", 8, 1, 0, 32);
	
	srand(static_cast<unsigned int>(time(NULL)));

	for (float y = -50; y < 50.0f; ++y)
	{
		for (float x = -50; x < 50.0f; ++x)
		{
#ifdef BATCH_TEST
			sprites.emplace_back(new Meow::TileSprite(Meow::Maths::vec3(x, y, 0), Meow::Maths::vec2(0.9f, 0.9f),
				Meow::Maths::vec4(0.0f, rand() % 10 / 10.0f, 0.0f, 1.0f), &shader));
#else
			sprites.emplace_back(new Meow::Sprite(Meow::Maths::vec3(x + 0.5f, y + 0.5f, 0), Meow::Maths::vec2(0.9f, 0.9f),
				Meow::Maths::vec4(0.0f, rand() % 10 / 10.0f, 0.0f, 1.0f), &shader, &texture));
#endif 
		}
	}
	
	//sprites.emplace_back(new Meow::AnimatedSprite(Meow::Maths::vec3(0.0f, 0.0f, 0.0f), Meow::Maths::vec2(40.0f, 40.0f), Meow::Maths::vec4(1.0f, 1.0f, 1.0f, 1.0f), &animatedSpriteShader,
		//&animatedSprite));

	Meow::Utils::Timer timer, t2;
	
	float lastTime = 0.0f;

	t2.reset();
	while (!window->closed())
	{
		float now = static_cast<float>(window->getWindowTimeNow());
		float deltaTime = now - lastTime;
		lastTime = now;
		
		window->update();
		timer.reset();

		renderer.begin();

		for (unsigned int i = 0; i < sprites.size(); ++i)
		{
#ifndef BATCH_TEST
			((Meow::Sprite*)(sprites[i]))->addRotation(1.0f);
#endif // !BATCH_TEST
			renderer.submit(sprites[i]);
		}

		texture.bind();

		renderer.end();
		renderer.flush(deltaTime);

		if (t2.getElapsedTime() > 1000000)
		{
			t2.reset();
			printf("%d\n", static_cast<int>(1000000 / timer.getElapsedTime()));
		}
	}
}