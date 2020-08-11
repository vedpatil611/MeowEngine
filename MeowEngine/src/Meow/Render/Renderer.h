#pragma once

#include <glad/glad.h>
#include <Meow/Core.h>
#include <Meow/Log.h>

#ifdef DEBUG
	#define ASSERT(x) if(!(x)) __debugbreak();
	#define GLCALL(func) GlClearError();			\
		func;										\
		ASSERT(GlLogCall(#func, __FILE__, __LINE__))
#else
	#define ASSERT(x)
	#define GLCALL(func) func; 
#endif 

void GlClearError();
bool GlLogCall(const char* functionName, const char* file, const int& line);

namespace Meow
{
	class Renderer
	{
	};
}