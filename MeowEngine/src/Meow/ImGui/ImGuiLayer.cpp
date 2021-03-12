#include "MeowPCH.h"
#include "ImGuiLayer.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Meow/Application.h"

#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "imgui.h"
#include "Meow/ImGui/openGL/imgui_impl_opengl3.h"
#include "Meow/ImGui/openGL/imgui_impl_glfw.h"

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Meow {

	ImGuiLayer::ImGuiLayer()
		: Layer() {}
	
	ImGuiLayer::~ImGuiLayer()
	{ }
	
	void ImGuiLayer::onAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigViewportsNoAutoMerge = true;
		//io.ConfigViewportsNoTaskBarIcon = true;

		ImGui::StyleColorsDark();

		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		auto* window = Application::getApplication().getWindow();
		ImGui_ImplGlfw_InitForOpenGL(window->getWindow(), true);

		/*io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
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
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;*/

		ImGui_ImplOpenGL3_Init("#version 450");
	}
	
	void ImGuiLayer::onUpdate()
	{
		//auto* window = Application::getApplication().getWindow();
		//ImGuiIO& io = ImGui::GetIO();
		//io.DisplaySize = ImVec2(window->getWidth(), window->getHeight());

		//ImGui_ImplOpenGL3_NewFrame();
		//ImGui::NewFrame();

		//float time = static_cast<float>(glfwGetTime());
		//io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0 / 60.0);
		//m_Time = time;

		//static bool showDemo = true;
		//ImGui::ShowDemoWindow(&showDemo);

		//ImGui::Render();
		//ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	
	void ImGuiLayer::onDettach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
	
	void ImGuiLayer::onEvent(Event& e)
	{
	/*	EventDispatcher dispatcher(e);
		dispatcher.dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(ImGuiLayer::mouseButtonPressedCallback));
		dispatcher.dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::mouseButtonReleasedCallback));
		dispatcher.dispatch<MouseMovedEvent>(BIND_EVENT_FN(ImGuiLayer::mouseMovedCallback));
		dispatcher.dispatch<MouseScrolledEvent>(BIND_EVENT_FN(ImGuiLayer::mouseScrollCallback));
		dispatcher.dispatch<KeyPressedEvent>(BIND_EVENT_FN(ImGuiLayer::keyPressedCallback));
		dispatcher.dispatch<KeyReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::keyReleasedCallback));
		dispatcher.dispatch<KeyTypedEvent>(BIND_EVENT_FN(ImGuiLayer::keyTypedCallback));*/
	}

	void ImGuiLayer::begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::onRender()
	{
		//static bool showDemo = true;
		//ImGui::ShowDemoWindow(&showDemo);
	}

	void ImGuiLayer::end()
	{
		ImGuiIO& io = ImGui::GetIO();
		Window* window = Application::getApplication().getWindow();
		io.DisplaySize = ImVec2(window->getWidth(), window->getHeight());

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	/*bool ImGuiLayer::windowResizeCallback(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.getWidth(), e.getHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.getWidth(), e.getHeight());
		return false;
	}

	bool ImGuiLayer::mouseButtonPressedCallback(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.getMouseButton()] = true;
		return true;
	}
	
	bool ImGuiLayer::mouseButtonReleasedCallback(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.getMouseButton()] = false;
		return true;
	}
	
	bool ImGuiLayer::mouseMovedCallback(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.getX(), e.getY());
		return false;
	}
	
	bool ImGuiLayer::mouseScrollCallback(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel += e.getY();
		io.MouseWheelH += e.getX();
		return true;
	}
	
	bool ImGuiLayer::keyPressedCallback(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.getKeyCode()] = true;
		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
		return true;
	}
	
	bool ImGuiLayer::keyReleasedCallback(KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.getKeyCode()] = false;
		return true;
	}
	
	bool ImGuiLayer::keyTypedCallback(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.getKeyCode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter(static_cast<unsigned char>(keycode));

		return true;
	}*/
}