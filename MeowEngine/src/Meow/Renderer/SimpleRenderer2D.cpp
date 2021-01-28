#include <MeowPCH.h>
#include "SimpleRenderer2D.h"
#include "AnimatedSprite.h"

namespace Meow
{
    SimpleRenderer2D::SimpleRenderer2D()
    {
        m_RenderQueue = new std::deque<const Renderable2D*>();
    }

    SimpleRenderer2D::~SimpleRenderer2D()
    {
        delete m_RenderQueue;
    }

    void SimpleRenderer2D::begin()
    {
        m_RenderQueue->clear();
    }

    void SimpleRenderer2D::submit(const Renderable2D* renderable)
	{
		m_RenderQueue->push_back(renderable);
	}

	void SimpleRenderer2D::flush()
	{
        while (!m_RenderQueue->empty())
        {
            if (dynamic_cast<const AnimatedSprite*>(m_RenderQueue->front()) == nullptr)
            {
                const Sprite* renderable = (Sprite*)m_RenderQueue->front();

                renderable->getShader()->enable();
                renderable->getTexture()->bind();

			    auto* vao = renderable->getVAO();
			    auto* ibo = renderable->getIBO();

			    vao->bind();
                ibo->bind();

                renderable->updateUniforms();

                GLCALL(glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_SHORT, nullptr));
                
                renderable->getTexture()->unbind();
                ibo->unbind();
                vao->unbind();

                m_RenderQueue->pop_front();
            }
            else
            {
                const AnimatedSprite* renderable = (AnimatedSprite*)m_RenderQueue->front();

                renderable->getShader()->enable();
                renderable->getTexture()->bind();

                auto* vao = renderable->getVAO();
                auto* ibo = renderable->getIBO();

                vao->bind();
                ibo->bind();

                renderable->updateUniforms();

                GLCALL(glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_SHORT, nullptr));

                renderable->getTexture()->unbind();
                ibo->unbind();
                vao->unbind();

                m_RenderQueue->pop_front();
            }
        }
	}

    void SimpleRenderer2D::end() {}
}