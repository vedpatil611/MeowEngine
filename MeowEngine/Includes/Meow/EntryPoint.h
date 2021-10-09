#pragma once

extern Meow::Application* Meow::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Meow::CreateApplication();
	app->Run();
	Meow::g_ActiveShader.reset();
	delete app;

	return 0;
}