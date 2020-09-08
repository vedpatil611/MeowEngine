#pragma once

#include <glad/glad.h>
#include <Meow/Core.h>
#include "MeowPCH.h"
#include "Renderer2D.h"

namespace Meow
{
	class MEOW_API SimpleRenderer2D: public Renderer2D
	{
	private:
		std::deque<const Renderable2D*> *m_RenderQueue;
	public:
		SimpleRenderer2D();
		~SimpleRenderer2D();

		void submit(const Renderable2D* renderable) override;
		void flush() override;
	};
}