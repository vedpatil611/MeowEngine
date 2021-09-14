#pragma once

#include <Meow/Core.h>

namespace Meow
{
	class MEOW_API Renderer2D
	{
	protected:
		virtual void submit(const Rc<class Renderable2D> renderable) = 0;
		virtual void flush(float delta) = 0;
	};
}