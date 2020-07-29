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
	#endif 
#endif

namespace Meow {

	MEOW_API void print();
}