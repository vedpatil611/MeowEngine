#pragma once

#include "Meow/Core.h"

namespace Meow
{
	class MEOW_API GraphicsContext
	{
	public:
		virtual void init() = 0;
		virtual void swapBuffers() = 0;
	};
}