#pragma once

#include <memory>

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

template <typename T>
using Rc = std::shared_ptr<T>;

template <typename T>
using Unique = std::unique_ptr<T>;

namespace Meow
{
	inline static Rc<class Window> g_Window = nullptr;
	inline static Rc<class Shader> g_ActiveShader = nullptr;
	inline static Rc<class Application> g_App = nullptr;
	
	MEOW_API Rc<class Shader> getActiveShader();
	MEOW_API void setActiveShader(Rc<class Shader> shader);
}

// Key codes
#define MEOW_KEY_UNKNOWN            -1

#define MEOW_KEY_SPACE              32
#define MEOW_KEY_APOSTROPHE         39  /* ' */
#define MEOW_KEY_COMMA              44  /* , */
#define MEOW_KEY_MINUS              45  /* - */
#define MEOW_KEY_PERIOD             46  /* . */
#define MEOW_KEY_SLASH              47  /* / */
#define MEOW_KEY_0                  48
#define MEOW_KEY_1                  49
#define MEOW_KEY_2                  50
#define MEOW_KEY_3                  51
#define MEOW_KEY_4                  52
#define MEOW_KEY_5                  53
#define MEOW_KEY_6                  54
#define MEOW_KEY_7                  55
#define MEOW_KEY_8                  56
#define MEOW_KEY_9                  57
#define MEOW_KEY_SEMICOLON          59  /* ; */
#define MEOW_KEY_EQUAL              61  /* = */
#define MEOW_KEY_A                  65
#define MEOW_KEY_B                  66
#define MEOW_KEY_C                  67
#define MEOW_KEY_D                  68
#define MEOW_KEY_E                  69
#define MEOW_KEY_F                  70
#define MEOW_KEY_G                  71
#define MEOW_KEY_H                  72
#define MEOW_KEY_I                  73
#define MEOW_KEY_J                  74
#define MEOW_KEY_K                  75
#define MEOW_KEY_L                  76
#define MEOW_KEY_M                  77
#define MEOW_KEY_N                  78
#define MEOW_KEY_O                  79
#define MEOW_KEY_P                  80
#define MEOW_KEY_Q                  81
#define MEOW_KEY_R                  82
#define MEOW_KEY_S                  83
#define MEOW_KEY_T                  84
#define MEOW_KEY_U                  85
#define MEOW_KEY_V                  86
#define MEOW_KEY_W                  87
#define MEOW_KEY_X                  88
#define MEOW_KEY_Y                  89
#define MEOW_KEY_Z                  90
#define MEOW_KEY_LEFT_BRACKET       91  /* [ */
#define MEOW_KEY_BACKSLASH          92  /* \ */
#define MEOW_KEY_RIGHT_BRACKET      93  /* ] */
#define MEOW_KEY_GRAVE_ACCENT       96  /* ` */
#define MEOW_KEY_WORLD_1            161 /* non-US #1 */
#define MEOW_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define MEOW_KEY_ESCAPE             256
#define MEOW_KEY_ENTER              257
#define MEOW_KEY_TAB                258
#define MEOW_KEY_BACKSPACE          259
#define MEOW_KEY_INSERT             260
#define MEOW_KEY_DELETE             261
#define MEOW_KEY_RIGHT              262
#define MEOW_KEY_LEFT               263
#define MEOW_KEY_DOWN               264
#define MEOW_KEY_UP                 265
#define MEOW_KEY_PAGE_UP            266
#define MEOW_KEY_PAGE_DOWN          267
#define MEOW_KEY_HOME               268
#define MEOW_KEY_END                269
#define MEOW_KEY_CAPS_LOCK          280
#define MEOW_KEY_SCROLL_LOCK        281
#define MEOW_KEY_NUM_LOCK           282
#define MEOW_KEY_PRINT_SCREEN       283
#define MEOW_KEY_PAUSE              284
#define MEOW_KEY_F1                 290
#define MEOW_KEY_F2                 291
#define MEOW_KEY_F3                 292
#define MEOW_KEY_F4                 293
#define MEOW_KEY_F5                 294
#define MEOW_KEY_F6                 295
#define MEOW_KEY_F7                 296
#define MEOW_KEY_F8                 297
#define MEOW_KEY_F9                 298
#define MEOW_KEY_F10                299
#define MEOW_KEY_F11                300
#define MEOW_KEY_F12                301
#define MEOW_KEY_F13                302
#define MEOW_KEY_F14                303
#define MEOW_KEY_F15                304
#define MEOW_KEY_F16                305
#define MEOW_KEY_F17                306
#define MEOW_KEY_F18                307
#define MEOW_KEY_F19                308
#define MEOW_KEY_F20                309
#define MEOW_KEY_F21                310
#define MEOW_KEY_F22                311
#define MEOW_KEY_F23                312
#define MEOW_KEY_F24                313
#define MEOW_KEY_F25                314
#define MEOW_KEY_KP_0               320
#define MEOW_KEY_KP_1               321
#define MEOW_KEY_KP_2               322
#define MEOW_KEY_KP_3               323
#define MEOW_KEY_KP_4               324
#define MEOW_KEY_KP_5               325
#define MEOW_KEY_KP_6               326
#define MEOW_KEY_KP_7               327
#define MEOW_KEY_KP_8               328
#define MEOW_KEY_KP_9               329
#define MEOW_KEY_KP_DECIMAL         330
#define MEOW_KEY_KP_DIVIDE          331
#define MEOW_KEY_KP_MULTIPLY        332
#define MEOW_KEY_KP_SUBTRACT        333
#define MEOW_KEY_KP_ADD             334
#define MEOW_KEY_KP_ENTER           335
#define MEOW_KEY_KP_EQUAL           336
#define MEOW_KEY_LEFT_SHIFT         340
#define MEOW_KEY_LEFT_CONTROL       341
#define MEOW_KEY_LEFT_ALT           342
#define MEOW_KEY_LEFT_SUPER         343
#define MEOW_KEY_RIGHT_SHIFT        344
#define MEOW_KEY_RIGHT_CONTROL      345
#define MEOW_KEY_RIGHT_ALT          346
#define MEOW_KEY_RIGHT_SUPER        347
#define MEOW_KEY_MENU               348

#define MEOW_KEY_LAST               MEOW_KEY_MENU

#define MEOW_MOD_SHIFT           0x0001
#define MEOW_MOD_CONTROL         0x0002
#define MEOW_MOD_ALT             0x0004
#define MEOW_MOD_SUPER           0x0008
#define MEOW_MOD_CAPS_LOCK       0x0010
#define MEOW_MOD_NUM_LOCK        0x0020

#define MEOW_MOUSE_BUTTON_1         0
#define MEOW_MOUSE_BUTTON_2         1
#define MEOW_MOUSE_BUTTON_3         2
#define MEOW_MOUSE_BUTTON_4         3
#define MEOW_MOUSE_BUTTON_5         4
#define MEOW_MOUSE_BUTTON_6         5
#define MEOW_MOUSE_BUTTON_7         6
#define MEOW_MOUSE_BUTTON_8         7
#define MEOW_MOUSE_BUTTON_LAST      MEOW_MOUSE_BUTTON_8
#define MEOW_MOUSE_BUTTON_LEFT      MEOW_MOUSE_BUTTON_1
#define MEOW_MOUSE_BUTTON_RIGHT     MEOW_MOUSE_BUTTON_2
#define MEOW_MOUSE_BUTTON_MIDDLE    MEOW_MOUSE_BUTTON_3
