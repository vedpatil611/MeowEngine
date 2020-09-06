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

// Deug break for debug config
#ifdef DEBUG
	#ifdef MEOW_PLATFORM_WINDOWS
		#define ASSERT(x) if(!(x)) __debugbreak();
		#define GLCALL(func) GlClearError();					\
				func;											\
				ASSERT(GlLogCall(#func, __FILE__, __LINE__))
	#else
		#define ASSERT(x)
		#define GLCALL(func) func; 
	#endif
#else
	#define ASSERT(x)
	#define GLCALL(func) func; 
#endif 

#define BIT(x) 1 << x

void GlClearError();
bool GlLogCall(const char* functionName, const char* file, const int& line);