#pragma once

#include "MeowPCH.h"
#include <Meow/Core.h>

namespace Meow
{
	class MEOW_API Texture
	{
	private:
		unsigned int m_TexID;
		const char* m_TexPath;
		int m_Width, m_Height, m_BPP;
	public:
		Texture(const char* texPath);
		~Texture();

		inline unsigned int getTextureId() const { return m_TexID; }

		void bind(unsigned int slot = 0) const;
		void unbind() const;
	};
}