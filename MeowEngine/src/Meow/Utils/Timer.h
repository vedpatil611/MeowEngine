#pragma once

#include <Meow/Core.h>

namespace Meow
{
	namespace Utils
	{
		class MEOW_API Timer
		{
		private:
			double start, end;
		public:
			Timer();
			~Timer();

			void reset();
			double getElapsedTime();
		};
	}
}