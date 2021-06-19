#include "MeowPCH.h"
#include "Application.h"

#include <functional>

#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"
#include <Meow/ImGui/openGL/imgui_impl_glfw.h>
#include <Meow/ImGui/openGL/imgui_impl_opengl3.h>
#include "ImGui/ExampleLayer.h"
#include <imgui.h>

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace Meow {
	Application::Application()
	{
		ASSERT(!s_Instance);
		s_Instance = this;

		window = new Window("Meow", 800, 800);
		window->setEventCallback(BIND_EVENT_FN(Application::onEvent));

		m_ImGuiLayer = new ExampleLayer();
		pushLayer(m_ImGuiLayer);
	}

	Application::~Application()
	{
		for (auto layer : m_LayerStack)
		{
			layer->onDettach();
		}

		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		SAFE_DELETE(window);

		if(s_Instance = this) s_Instance = nullptr;
	}

	void Application::Run()
	{

	}

	static bool onkeypressed(KeyPressedEvent& e)
	{
		return true;
	}

	static bool onmousemoved(MouseMovedEvent& e)
	{
		return true;
	}

	static bool onWindowResize(WindowResizeEvent& e)
	{
		return true;
	}

	void Application::onEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<KeyPressedEvent>(onkeypressed);
		dispatcher.dispatch<MouseMovedEvent>(onmousemoved);
		dispatcher.dispatch<WindowResizeEvent>(onWindowResize);

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); )
		{
			(*it++)->onEvent(event);
			if (event.handled) break;
		}
	}

	void Application::pushLayer(Layer* layer)
	{
		m_LayerStack.pushLayer(layer);
		layer->onAttach();
	}
}
