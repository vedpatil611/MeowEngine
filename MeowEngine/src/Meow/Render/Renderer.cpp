#include "Renderer.h"

#include <Meow/Log.h>
#include <GLFW/glfw3.h>

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
    Renderer::Renderer(const Window& window) 
    {
        window.setCurrentContext();

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            throw std::runtime_error("Failed to init glad");
    }
}
