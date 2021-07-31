#include "MeowPCH.h"
#include <Meow/Utils/Timer.h>

namespace Meow
{
	namespace Utils
	{
		Timer::Timer()
			: start(std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now())) {}

		void Timer::reset()
		{
			start = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now());
		}
		
		long long Timer::getElapsedTime()
		{
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now());
			return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		}
	}
}
