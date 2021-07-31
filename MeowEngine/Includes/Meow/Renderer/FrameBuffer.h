#pragma once

#include "MeowPCH.h"
#include <Meow/Core.h>

class MEOW_API FrameBuffer
{
private:
	unsigned int m_BufferId;
public:
	FrameBuffer();
	~FrameBuffer();

	void bind() const;
	void unbind() const;

	inline unsigned int getFrameBuffer() const { return m_BufferId; }
};