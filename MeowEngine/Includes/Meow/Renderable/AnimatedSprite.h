#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include "Sprite.h"

namespace Meow
{
	class MEOW_API AnimatedSprite :public Sprite
	{
	private:
		mutable float lastTime = 0.0f;
		mutable int m_CurrentIndex;
	public:
		AnimatedSprite(const Maths::vec3& position, const Maths::vec2& size, class Texture* texture, Rc<Shader> shader);
		~AnimatedSprite();

		void updateUniforms(float delta) const override;
	};
}