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
#include <vector>

#include <Meow.h>
#include <Meow/ImGui/ImGuiLayer.h>
#include <Meow/ImGui/ExampleLayer.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Renderer/Layer.h>
#include <Meow/Renderer/Shader.h>
#include <Meow/Renderer/TileSprite.h>
#include <Meow/Renderer/Texture.h>
#include <Meow/Renderer/TextureArray.h>
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
	//window->setIcon("assets/icon/Meow.png");

	Meow::Layer* layer = new Meow::Layer();
	pushLayer(layer);

	std::vector<Meow::Renderable2D*> sprites;

	auto proj = Meow::Maths::mat4::orthographic(-50, 50, -50, 50, -10, 10);
	Meow::Maths::mat4 model(1.0f);

	Meow::Shader* shader = Meow::Shader::create("shaders/texture2d.vert.glsl", "shaders/texture2d.frag.glsl");
	
	Meow::TextureArray texArray;

	int texIDs[32] = { 0 };

	for(int i = 0; i < texArray.size(); ++i)
	{
		printf("%d %d\n", i, texArray[i]->getTextureId());
		texIDs[i] = texArray[i]->getTextureId();
	}

	shader->bind();
	shader->setUniformMat4f("u_proj_mat", proj);
	
	//Meow::Texture tex("assets/Circle.png");
	//Meow::Texture tex2("assets/icon/Meow.png");
	
	shader->setUniform1iv("u_Texture", 32, texIDs);

	int s = 1;

	for (float i = -50.0; i < 50.0; i += 5.0f)
	{
		for (float j = -50.0; j < 50.0; j += 5.0f)
		{
			if (s == 1)
			{
				sprites.emplace_back(new Meow::TileSprite({ i, j, 0.0f }, { 4.9f, 4.9f }, texArray[0], shader));
				s = 2;
			}
			else
			{
				sprites.emplace_back(new Meow::TileSprite({ i, j, 0.0f }, { 4.9f, 4.9f }, texArray[1], shader));
				s = 1;
			}
		}
	}

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

		layer->submit(sprites);

		for (auto* layer : m_LayerStack)
			layer->onUpdate();

		for (auto* layer : m_LayerStack)
		{
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

	for (auto* x : sprites)
		delete x;

	delete shader;
}
