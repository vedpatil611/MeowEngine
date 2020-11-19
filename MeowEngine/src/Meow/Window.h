#pragma once

#include "Core.h"
#include <Meow/Maths/Maths.h>
struct GLFWwindow;

namespace Meow {

	/*enum KeyActions {
		KEY_RELEASE = 0,
		KEY_PRESSES = 1,
		KEY_REPEAT = 2
	};*/

	class MEOW_API Window {
		//friend GLFWwindow;
	private:
		GLFWwindow* m_Window;
		const char* m_Title;

		int m_Height, m_Width;
		double m_MouseX, m_MouseY;
		//static bool m_PressedKey[512];
	public:
		Window(const char* title, int width, int height);
		~Window();

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		inline double getMouseX() const { return m_MouseX; }
		inline double getMouseY() const { return m_MouseY; }
		inline GLFWwindow* getWindow() const { return m_Window; }

		void update();
		bool closed() const;
		void setCurrentContext() const;
		bool setVSyncEnable(bool b);
		void setBackgrondColor(const Meow::Maths::vec4& color);
	private:
		static void windowResizeCallback(GLFWwindow* window, int width, int height);
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}