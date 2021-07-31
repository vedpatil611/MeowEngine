#pragma once

#include <Meow/Core.h>
#include <chrono>

DISABLE_WARNINGS()

namespace Meow
{
	namespace Utils
	{
		class MEOW_API Timer
		{
		private:
			std::chrono::time_point<std::chrono::system_clock, std::chrono::microseconds> start, end;
		public:
			Timer();
			~Timer() = default;

			void reset();
			long long getElapsedTime();
		};
	}
}
