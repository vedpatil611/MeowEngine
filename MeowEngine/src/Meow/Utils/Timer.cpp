#include "MeowPCH.h"
#include "Timer.h"

namespace Meow
{
	namespace Utils
	{
		Timer::Timer()
			: start(std::chrono::high_resolution_clock::now()) {}

		void Timer::reset()
		{
			start = std::chrono::high_resolution_clock::now();
		}
		
		long long Timer::getElapsedTime()
		{
			end = std::chrono::high_resolution_clock::now();
			return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		}
	}
}
