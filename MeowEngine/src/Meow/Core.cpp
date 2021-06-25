#include <MeowPCH.h>

#include <glad/glad.h>
#include <Meow/Core.h>
#include <Meow/Utils/Log.h>
#include <Meow/Renderer/Shader.h>

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

namespace Meow
{
    Shader* getActiveShader()
    {
        return g_ActiveShader;
    }

    void setActiveShader(Shader* shader)
    {
        g_ActiveShader = shader;
    }
}
