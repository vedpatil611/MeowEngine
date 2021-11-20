#pragma once
#include <Meow/Utils/Timer.h>
#include <Meow/Events/ApplicationEvent.h>

extern Meow::Application* Meow::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Rc<Meow::Application>(Meow::CreateApplication());
	app->Run();

	Meow::Utils::Timer timer, t2;

	float lastTime = 0.0f;

	auto window = app->getWindow();
	auto layerStack = app->getLayerStack();

	t2.reset();
	while (!app->getWindow()->closed())
	{
		float now = static_cast<float>(window->getWindowTimeNow());
		float deltaTime = now - lastTime;
		lastTime = now;

		window->update();
		timer.reset();

		for (auto& layer : layerStack)
		{
			layer->clear();
		}

		Meow::AppUpdateEvent onAppUpdateEvent;
		window->callEvent(onAppUpdateEvent);

		for (auto& layer : layerStack)
		{
			//layer->clear();
			//layer->onUpdate();
			//layer->begin();
			layer->onRender(deltaTime);
			//layer->end();
		}

		window->swapBuffer();

		static Meow::AppRenderEvent onRenderEvent;
		window->callEvent(onRenderEvent);

		/*if (t2.getElapsedTime() > 1000000)
		{
			t2.reset();
			printf("%d\n", static_cast<int>(1000000 / timer.getElapsedTime()));
			printf("%d\n", window->closed());
		}*/
	}
	//while(a)
	//app->Loop();
	Meow::g_ActiveShader.reset();
	//delete app;

	return 0;
}
