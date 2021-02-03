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
		float m_fps;
		int m_SpriteCountX, m_SpriteCountY;
		int m_StartIndex;
		float lastTime = 0.0f;
	public:
		AnimatedSprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4 colour, Shader* shader, Texture* texture, int spriteCountX, int spriteCountY, int startIndex, float fps);
		~AnimatedSprite() override;

		void updateUniforms(float delta) override;
	};
}