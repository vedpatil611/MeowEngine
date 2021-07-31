#include "MeowPCH.h"
#include <Meow/Renderer/FrameBuffer.h>

#include <glad/glad.h>

FrameBuffer::FrameBuffer()
{
	GLCALL(glGenFramebuffers(1, &m_BufferId));
	GLCALL(glBindFramebuffer(GL_FRAMEBUFFER, m_BufferId));
}

FrameBuffer::~FrameBuffer()
{
	GLCALL(glDeleteFramebuffers(1, &m_BufferId));
}

void FrameBuffer::bind() const
{
	GLCALL(glBindFramebuffer(GL_FRAMEBUFFER, m_BufferId));
}

void FrameBuffer::unbind() const
{
	GLCALL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
}
