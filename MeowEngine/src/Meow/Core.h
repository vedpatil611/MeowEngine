#pragma once

#ifdef MEOW_PLATFORM_WINDOWS
#ifdef MEOW_BUILD_DLL
#define MEOW_API __declspec(dllexport)
#else
#define MEOW_API __declspec(dllimport)
#endif 
#elif MEOW_PLATFORM_LINUX
#ifdef MEOW_BUILD_DLL
#define MEOW_API __attribute__((visibility("default")))
#else
#define MEOW_API
#endif 
#endif

#ifdef DEBUG
	#define ASSERT(x) if(!(x)) __debugbreak();
	#define GLCALL(func) func;
#else
	#define ASSERT(x)
	#define GLCALL(func) func; 
#endif 

