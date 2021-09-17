#include "MeowPCH.h"
#include <Meow/Utils/File.h>

#include <cstring>
#include <fstream>

namespace Meow {
    namespace Utils {
        std::string readFile(const char* filepath)
        {
            FILE* file = fopen(filepath, "rt");
            
            fseek(file, 0, SEEK_END);
            unsigned long length = ftell(file);
            std::string data(length + 1, 0);
            memset(data.data(), 0, length + 1);
            fseek(file, 0, SEEK_SET);
            fread(data.data(), 1, length, file);
            fclose(file);

            return data;
        }
    }
}

