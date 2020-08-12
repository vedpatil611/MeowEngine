#pragma once

#include "Core.h"

struct GLFWwindow;

namespace Meow {

	class MEOW_API Window {
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
	public:
		Window(const char* title, int width, int height);
		~Window();

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		inline GLFWwindow* getWindow() const { return m_Window; }

		void update();
		bool closed() const;
		void setCurrentContext() const;
	private:
		static void windowResizeCallback(GLFWwindow* window, int width, int height);
	};
}