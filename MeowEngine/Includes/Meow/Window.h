#pragma once

#include "Core.h"
#include <Meow/Maths/Maths.h>
#include <Meow/Events/Event.h>

#include <functional>

DISABLE_WARNINGS()

struct GLFWgamepadstate;
typedef struct GLFWgamepadstate GamepadState;
struct GLFWwindow;

namespace Meow {
	class MEOW_API Window {
	private:
		using EventCallbackFn = std::function<void(Event&)>;
		
		struct GLFWwindow* m_Window;
		const char* m_Title;

		int m_Height, m_Width;
		double m_MouseX, m_MouseY;
		bool m_PressedKey[1024] = { false };
		GamepadState* gamepadState;

		Rc<class GraphicsContext> m_GraphicsContext;

		EventCallbackFn eventCallback;
	public:
		Window(const char* title, int width, int height);
		~Window();

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		inline double getMouseX() const { return m_MouseX; }
		inline double getMouseY() const { return m_MouseY; }
		inline struct GLFWwindow* getWindow() const { return m_Window; }

		int isJoystickPresent() const;
		inline GamepadState* getGamepadState() const { return gamepadState; }

		void update();
		void swapBuffer();
		bool closed() const;
		void setCurrentContext() const;
		bool setVSyncEnable(const bool b);
		void setBackgrondColor(const Meow::Maths::vec4& color);
		void setIcon(const char* iconPath);
		double getWindowTimeNow();

		inline void setEventCallback(const EventCallbackFn& callback) { eventCallback = callback; }
		void callEvent(Event& event) const;
	private:
		static void windowResizeCallback(struct GLFWwindow* window, int width, int height);
		static void windowCloseCallback(struct GLFWwindow* window);
		static void keyCallback(struct GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouseButtonCallback(struct GLFWwindow* window, int button, int action, int mods);
		static void cursorPosCallback(struct GLFWwindow* window, double xPos, double yPos);
		static void scrollCallback(struct GLFWwindow* window, double xOffset, double yOffset);
		static void charCallback(struct GLFWwindow* window, unsigned int code);
	};
}