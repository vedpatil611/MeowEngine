#pragma once

#include "MeowPCH.h"
#include <Meow/Core.h>
#include <iostream>
#include <stdexcept>

#define COLOUR_RST		"\033[0;39m"
#define COLOUR_RED		"\033[1;31m"
#define COLOUR_GRN		"\033[1;32m"
#define COLOUR_YEL		"\033[1;33m"
#define COLOUR_MAG		"\033[1;35m"

#define LOG			std::cout << COLOUR_GRN
#define LOG_WARN	std::cout << COLOUR_YEL
#define LOG_ERROR	std::cout << COLOUR_RED
#define END_LOG		COLOUR_RST << std::endl

namespace Meow {
	class MEOW_API Log {
	public:
		template<typename ...Vargs>
		static void log(const char* fmt, Vargs... vargs)
		{
			char* s;
			char* t;
			char* p;
			//sscanf(fmt, "%s", s);
			/*while (sscanf(fmt, "%s %[^\n]%*c", t, s) > 1)
			{
				if (strcmp(t, "{}") == 0)
				{
					sprintf(p + strlen(p), "%s");
				}
			}*/
		}
	};
}