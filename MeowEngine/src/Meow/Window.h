#pragma once

#include "Core.h"
#include <Meow/Maths/Maths.h>
#include <Meow/Events/Event.h>

#include <functional>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct GLFWwindow;
typedef struct GLFWgamepadstate GamepadState;

//using EventCallbackFn = void(*)(Meow::Event&);
using EventCallbackFn = std::function<Meow::Event>();

namespace Meow {
	/*enum KeyActions {
		KEY_RELEASE = 0,
		KEY_PRESSES = 1,
		KEY_REPEAT = 2
	};*/

	class MEOW_API Window {
	private:
		GLFWwindow* m_Window;
		const char* m_Title;

		int m_Height, m_Width;
		double m_MouseX, m_MouseY;
		bool m_PressedKey[1024] = { false };
		GamepadState gamepadState;

		EventCallbackFn m_CallbackFunc;
	public:
		Window(const char* title, int width, int height);
		~Window();

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		inline double getMouseX() const { return m_MouseX; }
		inline double getMouseY() const { return m_MouseY; }
		inline GLFWwindow* getWindow() const { return m_Window; }

		inline int isJoystickPresent() const { return glfwJoystickPresent(GLFW_JOYSTICK_1); }
		inline GamepadState getGamepadState() const { return gamepadState; }

		void update();
		bool closed() const;
		void setCurrentContext() const;
		bool setVSyncEnable(bool b);
		void setBackgrondColor(const Meow::Maths::vec4& color);

		//inline void setEventCallback(const EventCallbackFn& callback) { m_CallbackFunc = callback; }
	private:
		static void windowResizeCallback(GLFWwindow* window, int width, int height);
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}