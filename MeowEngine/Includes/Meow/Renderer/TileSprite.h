#pragma once

#include <Meow/Core.h>
#include <Meow/Maths/Maths.h>
#include <Meow/Renderable/Renderable2D.h>
#include "Texture.h"

namespace Meow
{
	class MEOW_API TileSprite : public Renderable2D
	{
	private:
		class Shader* m_Shader;
	public:
		TileSprite(const Maths::vec3& position, const Maths::vec2& size, const Maths::vec4& colour, class Shader* shader);
		TileSprite(const Maths::vec3& position, const Maths::vec2& size, class Texture* texture, class Shader* shader);
		~TileSprite() override;

		inline class Shader* getShader() const override { return m_Shader; }
	};
}
