#pragma once

#include <Meow/Core.h>
#include "Renderable2D.h"

namespace Meow
{
	class MEOW_API Renderer2D
	{
	protected:
		virtual void submit(const Renderable2D& renderable) = 0;
		virtual void flush() = 0;
	};
}