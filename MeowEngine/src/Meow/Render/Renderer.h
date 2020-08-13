#pragma once

#include <glad/glad.h>
#include <Meow/Core.h>
#include <Meow/Window.h>
#include <Meow/Render/Shader.h>
#include <Meow/Maths/Maths.h>

#ifdef DEBUG
	#ifdef MEOW_PLATFORM_WINDOWS
		#define ASSERT(x) if(!(x)) __debugbreak();
		#define GLCALL(func) GlClearError();					\
				func;											\
				ASSERT(GlLogCall(#func, __FILE__, __LINE__))
	#endif
#else
	#define ASSERT(x)
	#define GLCALL(func) func; 
#endif 

void GlClearError();
bool GlLogCall(const char* functionName, const char* file, const int& line);

namespace Meow
{
	class MEOW_API Renderer
	{
	public:
		Renderer(const Window& window);

		void testRender(unsigned int count)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			GLCALL(glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_SHORT, nullptr));
		}
	};
}