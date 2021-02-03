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
		unsigned int m_Slot;
		static inline unsigned int provideSlotNo = 0;
	public:
		Texture(const char* texPath);
		~Texture();

		inline unsigned int getTextureId() const { return m_TexID; }
		inline unsigned int getSlot() const { return m_Slot; }
		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }

		void setSlot(unsigned int slotNo);

		void bind(unsigned int slot = 0) const;
		void unbind() const;
	};

	typedef Texture SpriteSheet;
}