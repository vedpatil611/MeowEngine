#pragma once

#include "MeowPCH.h"
#include <Meow/Core.h>

namespace Meow
{
	class MEOW_API Texture
	{
	protected:
		unsigned int m_TexID;
		const char* m_TexPath;
		int m_Width, m_Height, m_BPP;
		unsigned int m_Slot;
		unsigned char* m_Bits;
		static inline unsigned int provideSlotNo = 0;
	public:
		Texture(const char* texPath);
		virtual ~Texture();

		inline unsigned int getTextureId() const { return m_TexID; }
		inline unsigned int getSlot() const { return m_Slot; }
		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		inline unsigned char* getPixels() const { bind(m_Slot);  return m_Bits; }
		void setSlot(unsigned int slotNo);

		void bind(unsigned int slot = 0) const;
		void unbind() const;
	};
}