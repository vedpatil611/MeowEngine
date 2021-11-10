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
	:Meow::Application()
{
}

MeowApplication::~MeowApplication()
{
}

void MeowApplication::Run()
{
	auto window = Meow::Application::getWindow();
	window->setVSyncEnable(false);
	window->setBackgrondColor({ 0.0f, 0.0f, 0.0f, 1.0f });

	auto layer = Meow::Application::getBaseLayer();

	auto proj = Meow::Maths::mat4::orthographic(-50, 50, -50, 50, -10, 10);
	Meow::Maths::mat4 model(1.0f);

	auto shader = Meow::Shader::create("shaders/texture2d.vert.glsl", "shaders/texture2d.frag.glsl");
	Meow::setActiveShader(shader);

	auto circle = Meow::Texture::create("assets/Circle.png");
	auto catTex = Meow::Texture::create("assets/icon/Meow.png");

	shader->bind();
	shader->setUniformMat4f("u_proj_mat", proj);

	auto cat = Meow::Sprite::create({ 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f }, catTex, shader);

	//auto& layerStack = Meow::Application::getLayerStack();
	setKeyPressedCallback([cat](Meow::KeyPressedEvent& e) -> bool
		{
			switch (e.getKeyCode())
			{
			case MEOW_KEY_W:
			case MEOW_KEY_UP:
				cat->m_Position.y -= 0.5f;
				break;
			case MEOW_KEY_S:
			case MEOW_KEY_DOWN:
				cat->m_Position.y += 0.5f;
				break;
			case MEOW_KEY_A:
			case MEOW_KEY_LEFT:
				cat->m_Position.x -= 0.5f;
				break;
			case MEOW_KEY_D:
			case MEOW_KEY_RIGHT:
				cat->m_Position.x += 0.5f;
				break;
			}

			return true;
		}
	);

	setAppUpdateCallback([cat, layer](Meow::AppUpdateEvent& e) -> bool
		{
			layer->clear();
			layer->submit(cat);

			return true;
		}
	);
	/*Meow::Utils::Timer timer, t2;
	
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

		for (auto& layer : layerStack)
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
	}*/
}

void MeowApplication::Loop()
{
}
