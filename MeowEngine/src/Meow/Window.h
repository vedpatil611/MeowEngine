#pragma once

#include "Core.h"
#include <Meow/Maths/Maths.h>
#include <Meow/Events/Event.h>

#include <functional>

#ifndef __glad_h_
#include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>

#include <Meow/Renderer/GraphicsContext.h>
#include <Meow/Events/Event.h>

typedef struct GLFWgamepadstate GamepadState;

namespace Meow {
	class MEOW_API Window {
	private:
		using EventCallbackFn = std::function<void(Event&)>;
		
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;
		const char* m_Title;

		int m_Height, m_Width;
		double m_MouseX, m_MouseY;
		bool m_PressedKey[1024] = { false };
		GamepadState gamepadState;

		EventCallbackFn eventCallback;
	public:
		Window(const char* title, int width, int height);
		~Window();

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		inline double getMouseX() const { return m_MouseX; }
		inline double getMouseY() const { return m_MouseY; }
		inline GLFWwindow* getWindow() const { return m_Window; }

		int isJoystickPresent() const;
		inline GamepadState getGamepadState() const { return gamepadState; }

		void update();
		bool closed() const;
		void setCurrentContext() const;
		bool setVSyncEnable(bool b);
		void setBackgrondColor(const Meow::Maths::vec4& color);
		void setIcon(const char* iconPath);
		double getWindowTimeNow();

		inline void setEventCallback(const EventCallbackFn& callback) { eventCallback = callback; }
	private:
		static void windowResizeCallback(GLFWwindow* window, int width, int height);
		static void windowCloseCallback(GLFWwindow* window);
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void cursorPosCallback(GLFWwindow* window, double xPos, double yPos);
		static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
		static void charCallback(GLFWwindow* window, unsigned int code);
	};
}