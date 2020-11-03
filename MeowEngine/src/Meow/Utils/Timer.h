#pragma once

#include <Meow/Core.h>
#include <chrono>

namespace Meow
{
	namespace Utils
	{
		class MEOW_API Timer
		{
		private:
			std::chrono::steady_clock::time_point start, end;
		public:
			Timer();
			~Timer() = default;

			void reset();
			long long getElapsedTime();
		};
	}
}