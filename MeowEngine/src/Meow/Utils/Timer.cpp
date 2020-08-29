#include "MeowPCH.h"
#include "Timer.h"

#include<GLFW/glfw3.h>

namespace Meow
{
	namespace Utils
	{
		Timer::Timer()
			: start(glfwGetTime()) {}

		Timer::~Timer() 
		{
			end = glfwGetTime();
			double time = end-start;
		}

		void Timer::reset()
		{
			glfwSetTime(0);
			start = 0;
		}
		
		double Timer::getElapsedTime()
		{
			return glfwGetTime() - start;
		}
	}
}
