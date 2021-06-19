#pragma once

#include "Window.h"
#include "Events/Event.h"
#include "Renderer/LayerStack.h"
#include "ImGui/ImGuiLayer.h"

namespace Meow {
	class MEOW_API Application
	{
	protected:
		Window* window;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;

		inline static Application* s_Instance = nullptr;
	public:
		Application();
		virtual ~Application();

		virtual void Run();

		void onEvent(Event& event);
		void pushLayer(Layer* layer);

		static inline Application& getApplication() { return *s_Instance; }
		inline Window* getWindow() { return window; }
	};

	Application* CreateApplication();
}
