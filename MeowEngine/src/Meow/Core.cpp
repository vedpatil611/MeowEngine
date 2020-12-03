#include <MeowPCH.h>

#include <Meow/Core.h>
#include <Meow/Utils/Log.h>
#include <glad/glad.h>

void GlClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GlLogCall(const char* functionName, const char* file, const int& line)
{
    while (GLenum error = glGetError())
    {
        LOG_WARN << "[OpenGL error] (" << error << "): " << functionName << " " << file << ":" << line << END_LOG;
        return false;
    }
    return true;
}