#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include "Renderable2D.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Buffer.h"
#include "Texture.h"

namespace Meow
{
	class MEOW_API AnimatedSprite :public Renderable2D
	{
	private:
		Shader* shader;
		VertexArray* vertexArray;
		IndexBuffer* indexBuffer;
		Buffer* buffer;
		Texture* texture;
	public:
		AnimatedSprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour, const char* spriteSheets, float fps);
	};
}