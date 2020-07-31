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

		void update() const;
		bool closed() const;
	};
}