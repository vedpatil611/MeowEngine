#pragma once

#include <Meow/Core.h>
#include <vector>
#include <string>
#include <stdexcept>

#define COLOUR_RST		"\033[0;39m"
#define COLOUR_RED		"\033[1;31m"
#define COLOUR_GRN		"\033[1;32m"
#define COLOUR_YEL		"\033[1;33m"
#define COLOUR_MAG		"\033[1;35m"

#define LOG_WARN std::cout << COLOUR_YEL
#define LOG_ERROR std::cout << COLOUR_RED
#define END_LOG COLOUR_RST << std::endl

namespace Meow {
	class MEOW_API Printable {
	public:
		virtual std::string Print() = 0;
	};

	class MEOW_API Log {
	public:
		static void log(const char* format, const std::vector<Printable*>& printList);
		static void warn(const char* format, const std::vector<Printable*>& printList);
		static void error(const char* format, const std::vector<Printable*>& printList);
		static void fatal_exception(const char* format, const std::exception& e,const std::vector<Printable*>& printList);
	};
}