#include <MeowPCH.h>
#include "MeowApplication.h"

#ifdef MEOW_PLATFORM_WINDOWS
#include <Windows.h>
#endif 

#include <ctime>
#include <math.h>
#include <vector>

#include <Meow.h>
#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Renderer/Layer.h>
#include <Meow/Renderable/Sprite.h>
#include <Meow/Renderer/Shader.h>
#include <Meow/Renderer/Texture.h>
#include <Meow/Utils/Timer.h>
template <typename T>
using Rc = std::shared_ptr<T>;
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

	Meow::Layer* layer = getBaseLayer();

	auto proj = Meow::Maths::mat4::orthographic(-50, 50, -50, 50, -10, 10);
	Meow::Maths::mat4 model(1.0f);

	Rc<Meow::Shader> shader = Meow::Shader::create("shaders/texture2d.vert.glsl", "shaders/texture2d.frag.glsl");
	Meow::setActiveShader(shader.get());

	int texIDs[32] = { 0 };

	for(int i = 0; i < 32; ++i)
	{
		texIDs[i] = i;
	}

	Meow::Texture circle("assets/Circle.png");
	Meow::Texture catTex("assets/icon/Meow.png");

	shader->bind();
	shader->setUniformMat4f("u_proj_mat", proj);
	
	shader->setUniform1iv("u_Texture", 32, texIDs);

	//int s = 1;
	Meow::Sprite* cat = new Meow::Sprite({ 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f }, &catTex, shader);

	/*for (float i = -50.0; i < 50.0; i += 5.0f)
	{
		for (float j = -50.0; j < 50.0; j += 5.0f)
		{
			if (s == 1)
			{
				sprites.emplace_back(new Meow::TileSprite({ i, j, 0.0f }, { 4.9f, 4.9f }, &circle, shader));
				s = 2;
			}
			else
			{
				sprites.emplace_back(new Meow::TileSprite({ i, j, 0.0f }, { 4.9f, 4.9f }, &cat, shader));
				s = 1;
			}
		}
	}*/

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

		layer->clear();
		layer->submit(cat);

		for (auto* layer : m_LayerStack)
		{
			layer->onUpdate();
			layer->begin();
			layer->onRender(deltaTime);
			layer->end();
		}

		if (t2.getElapsedTime() > 1000000)
		{
			t2.reset();
			printf("%d\n", static_cast<int>(1000000 / timer.getElapsedTime()));
			printf("%d\n", window->closed());
		}
	}

	//for (auto* x : sprites)
		//delete x;

	delete cat;
}
