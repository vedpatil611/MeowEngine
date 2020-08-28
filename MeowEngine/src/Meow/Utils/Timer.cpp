#include "MeowPCH.h"
#include "Timer.h"

namespace Meow
{
	namespace Utils
	{
		Timer::Timer()
			: start(std::chrono::high_resolution_clock::now()) {}

		Timer::~Timer() 
		{
			end = std::chrono::high_resolution_clock::now();
			auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		}

		void Timer::reset()
		{
			start = std::chrono::high_resolution_clock::now();
		}
		
		float Timer::elapsedTime()
		{
			return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		}
	}
}
