#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include "Sprite.h"
#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Buffer.h"
#include "Texture.h"

namespace Meow
{
	class MEOW_API AnimatedSprite :public Sprite
	{
	private:
		mutable float lastTime = 0.0f;
		mutable int m_CurrentIndex;
	public:
		AnimatedSprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour, Shader* shader, Texture* texture);
		~AnimatedSprite();

		void updateUniforms(float delta) const override;
	};
}