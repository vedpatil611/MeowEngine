#include <MeowPCH.h>
#include "SimpleRenderer2D.h"
#include "StaticSprite.h"
namespace Meow
{
	void SimpleRenderer2D::submit(const Renderable2D* renderable)
	{
		m_RenderQueue.push_back(renderable);
	}
	void SimpleRenderer2D::flush()
	{
        while (!m_RenderQueue.empty())
        {
            const StaticSprite* renderable = (StaticSprite*)m_RenderQueue.front();
            renderable->getVAO()->bind();
            renderable->getIBO()->bind();
            renderable->getShader()->enable();
            renderable->getShader()->setUniformMat4f("u_model_mat", Maths::mat4::translation(renderable->getPositions()));
            GLCALL(glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr));
            renderable->getIBO()->unbind();
            renderable->getVAO()->unbind();

            m_RenderQueue.pop_front();
        }
	}
}