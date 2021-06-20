#include "MeowPCH.h"
#include "ExampleLayer.h"

#include "imgui.h"

namespace Meow
{
	ExampleLayer::ExampleLayer()
		:ImGuiLayer()
	{

	}

	ExampleLayer::~ExampleLayer()
	{

	}

	void ExampleLayer::onAttach()
	{
		ImGuiLayer::onAttach();
	}

	void ExampleLayer::onUpdate()
	{
		ImGuiLayer::onUpdate();
	}

	void ExampleLayer::onDettach()
	{
		ImGuiLayer::onDettach();
	}

	void ExampleLayer::onEvent(Event& e)
	{
		ImGuiLayer::onEvent(e);
	}

	void ExampleLayer::submit(const std::vector<Renderable2D*>& sprites)
	{
		renderer.begin();

		for (auto* s : sprites)
			renderer.submit(s);

		renderer.end();
	}

	void ExampleLayer::begin()
	{
		ImGuiLayer::begin();
	}

	void ExampleLayer::onRender(float delta)
	{
		ImGuiLayer::onRender(delta);
		
		//renderer.flush(delta);

		ImGui::Begin("Test");
		ImGui::Text("Hello");
		ImGui::End();

		ImGui::Begin("The");
		ImGui::Text("World");
		ImGui::End();
	}
	void ExampleLayer::end()
	{
		ImGuiLayer::end();
	}
}
