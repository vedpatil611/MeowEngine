#pragma once

#include <Meow/Core.h>

#include "IndexBuffer.h"
#include "Renderable2D.h"
#include "Shader.h"
#include "VertexArray.h"

namespace Meow
{
	class MEOW_API Texture2D: Renderable2D
	{
	private:
		Shader* shader;
		VertexArray* m_VertexArray;
		IndexBuffer* m_IndexBuffer;
	};
}