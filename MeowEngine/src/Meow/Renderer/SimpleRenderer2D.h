#pragma once

#include <glad/glad.h>
#include <Meow/Core.h>
#include "MeowPCH.h"
#include "Renderer2D.h"

#pragma depricated
namespace Meow
{
	class MEOW_API SimpleRenderer2D: public Renderer2D
	{
	private:
		std::deque<const Renderable2D*> m_RenderQueue;
	public:
		void submit(const Renderable2D* renderable) override;

		void flush() override;
	};
}