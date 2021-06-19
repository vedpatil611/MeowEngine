#pragma once

extern Meow::Application* Meow::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Meow::CreateApplication();
	app->Run();
	delete app;

	return 0;
}