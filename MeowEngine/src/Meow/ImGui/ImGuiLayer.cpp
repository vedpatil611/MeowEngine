#include "MeowPCH.h"
#include "ImGuiLayer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Meow/Application.h"
#include "Meow/ImGui/openGL/imgui_impl_opengl3.h"

namespace Meow {

	ImGuiLayer::ImGuiLayer()
		: Layer() {}
	
	ImGuiLayer::~ImGuiLayer()
	{ }
	
	void ImGuiLayer::onAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.BackendPlatformName = "imgui_impl_glfw";

		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

		ImGui_ImplOpenGL3_Init("#version 450");
	}
	
	void ImGuiLayer::onUpdate()
	{

		auto* window = Application::getApplication().getWindow();
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(window->getWidth(), window->getHeight());

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		float time = static_cast<float>(glfwGetTime());
		io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0 / 60.0);
		m_Time = time;

		static bool showDemo = true;
		ImGui::ShowDemoWindow(&showDemo);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	}
	
	void ImGuiLayer::onDettach()
	{
	}
	
	void ImGuiLayer::onEvent(Event& e)
	{
	}
}