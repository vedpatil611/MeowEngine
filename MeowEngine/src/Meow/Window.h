#pragma once

#include "Core.h"

struct GLFWwindow;

namespace Meow {

	class MEOW_API Window {
		friend GLFWwindow;
	public:
		float vertex[6] = {
			 0.0f,  0.5f,
			-0.5f, -0.5f,
			 0.5f, -0.5f
		};
	private:
		GLFWwindow* m_Window;
		const char* m_Title;
		int m_Height, m_Width;
		double m_MouseX, m_MouseY;
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
	private:
		static void windowResizeCallback(GLFWwindow* window, int width, int height);
	};
}