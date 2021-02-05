#pragma once

#include <Meow/Core.h>
#include "Texture.h"

namespace Meow
{
	class MEOW_API SpriteSheet : public Texture
	{
	private:
		float m_fps;
		int m_SpriteCountX, m_SpriteCountY;
		int m_StartIndex;
	public:
		SpriteSheet(const char* texPath, int spriteCountX, int spriteCountY, int startIndex, float fps);
		~SpriteSheet() {};

		inline const float getFps() const { return m_fps; }
		inline const int getSpriteCountX() const { return m_SpriteCountX; }
		inline const int getSpriteCountY() const { return m_SpriteCountY; }
		inline const int getStartIndex() const { return m_StartIndex; }
	};
}