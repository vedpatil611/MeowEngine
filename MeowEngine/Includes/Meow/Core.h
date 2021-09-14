#pragma once

#ifdef MEOW_PLATFORM_WINDOWS
	#ifdef MEOW_BUILD_DLL
		#define MEOW_API __declspec(dllexport)
		#define EXPORT_EXTERN 
	#else
		#define MEOW_API __declspec(dllimport)
		#define EXPORT_EXTERN extern
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

#ifdef MEOW_PLATFORM_WINDOWS
	#define DISABLE_WARNINGS()				\
		__pragma(warning(disable : 4251))			
#elif MEOW_PLATFORM_LINUX
	#define DISABLE_WARNINGS()
#else
	#define DISABLE_WARNINGS()
#endif

#define BIT(x) (1 << x)

#define SAFE_DELETE(x) delete x; x = nullptr;

void GlClearError();
bool GlLogCall(const char* functionName, const char* file, const int& line);

namespace Meow
{
	static class Shader* g_ActiveShader = nullptr;
	
	MEOW_API class Shader* getActiveShader();
	MEOW_API void setActiveShader(class Shader* shader);
}

template <typename T>
using Rc = std::shared_ptr<T>;

template <class T, class... Types>
using newRc = Rc<T>(*)(Types&&... Args);

template <typename T>
using Unique = std::unique_ptr<T>;

template <class T, class... Types>
using newUnique = Unique<T>(*)(Types&&... Args);
