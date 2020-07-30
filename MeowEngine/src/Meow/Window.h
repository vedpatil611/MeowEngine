#pragma once

#include "Core.h"

struct GLFWwindow;

namespace Meow {

	class MEOW_API Window {

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