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
#include <Meow/Utils/Timer.h>
#include <Meow.h>

#include <Meow/Renderer/Layer.h>
#include <Meow/ImGui/ImGuiLayer.h>

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

	pushLayer(new Meow::Layer());
	pushLayer(new Meow::ImGuiLayer());

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

		for (auto* layer : m_LayerStack)
			layer->onUpdate();

		if (t2.getElapsedTime() > 1000000)
		{
			t2.reset();
			printf("%d\n", static_cast<int>(1000000 / timer.getElapsedTime()));
		}
	}
}