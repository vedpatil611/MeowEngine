#include "MeowPCH.h"
#include "SpriteSheet.h"

namespace Meow
{
	SpriteSheet::SpriteSheet(const char* texPath, int spriteCountX, int spriteCountY, int startIndex, float fps)
		:Texture(texPath), m_SpriteCountX(spriteCountX), m_SpriteCountY(spriteCountY), m_StartIndex(startIndex), m_fps(fps) {}
}