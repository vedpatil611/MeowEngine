#include "Renderer.h"

#include <iostream>

void GlClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GlLogCall(const char* functionName, const char* file, const int& line)
{
    while (GLenum error = glGetError())
    {
        std::cout << COLOUR_RED << "[OpenGL error] (" << error << "): " << functionName << " " << file << ":" << line << COLOUR_RST << std::endl;
        return false;
    }
    return true;
}
