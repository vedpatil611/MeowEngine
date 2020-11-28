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

		void setSlot(unsigned int slotNo);

		void bind(unsigned int slot) const;
		void bind() const;
		void unbind() const;
	};
}