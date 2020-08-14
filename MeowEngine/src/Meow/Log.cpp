#include "MeowPCH.h"
#include "Log.h"

namespace Meow
{
	void Log::log(const char* format, const std::vector<Printable*>& printList)
	{
		#ifdef DEBUG
		std::stringstream ss(format);
		std::string s;
		int argCount = 0;

		std::cout << COLOUR_GRN;
		while (ss >> s)
		{
			if (s == "{}")
			{
				std::cout << printList[argCount++]->Print() << " ";
			}
			else
			{
				std::cout << s << " ";
			}
		}
		std::cout << COLOUR_RST << std::endl;
		#endif 
	}

	void Log::warn(const char* format, const std::vector<Printable*>& printList)
	{
		#ifdef DEBUG
		std::stringstream ss(format);
		std::string s;
		int argCount = 0;

		std::cout << COLOUR_YEL << "Warning: ";
		while (ss >> s)
		{
			if (s == "{}")
			{
				std::cout << printList[argCount++]->Print() << " ";
			}
			else
			{
				std::cout << s << " ";
			}
		}
		std::cout << COLOUR_RST << std::endl;
		#endif 
	}
	void Log::error(const char* format, const std::vector<Printable*>& printList)
	{
		#ifdef DEBUG
		std::stringstream ss(format);
		std::string s;
		int argCount = 0;

		std::cout << COLOUR_RED << "Error: ";
		while (ss >> s)
		{
			if (s == "{}")
			{
				std::cout << printList[argCount++]->Print() << " ";
			}
			else
			{
				std::cout << s << " ";
			}
		}
		std::cout << COLOUR_RST << std::endl;
		#endif 
	}
	void Log::fatal_exception(const char* format, const std::exception& e, const std::vector<Printable*>& printList)
	{
		#ifdef DEBUG
		std::stringstream ss(format);
		std::string s;
		int argCount = 0;

		std::cout << COLOUR_MAG << "Fatal exception: ";
		while (ss >> s)
		{
			if (s == "{}")
			{
				std::cout << printList[argCount++]->Print() << " ";
			}
			else
			{
				std::cout << s << " ";
			}
		}
		std::cout << COLOUR_RST << std::endl;
		throw e;
		#endif 
	}
}