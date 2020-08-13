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
    void Renderer::submit(const Renderable2D& renderable)
    {
        m_RenderQueue.push_back(&renderable);
    }

    void Renderer::flush()
    {
        while (!m_RenderQueue.empty())
        {
            const Renderable2D& renderable = *m_RenderQueue.front();
            renderable.getVAO()->bind();
            renderable.getIBO()->bind();
            renderable.getShader().enable();
            GLCALL(glDrawElements(GL_TRIANGLES, renderable.getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr));
            renderable.getShader().disable();
            renderable.getIBO()->unbind();
            renderable.getVAO()->unbind();

            m_RenderQueue.pop_front();
        }
    }
}
