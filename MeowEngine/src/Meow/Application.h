#pragma once

#include "Window.h"

namespace Meow {
	class MEOW_API Application
	{
	public:
		Application();
		~Application();

		virtual void Run();
	};

	Application* CreateApplication();
}
