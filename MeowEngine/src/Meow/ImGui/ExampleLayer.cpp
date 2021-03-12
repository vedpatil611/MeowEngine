#include "MeowPCH.h"
#include "ExampleLayer.h"

#define IMGUI_IMPL_OPENGL_LOADER_GLAD
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

	void ExampleLayer::begin()
	{
		ImGuiLayer::begin();
	}

	void ExampleLayer::onRender()
	{
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
