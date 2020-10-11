#pragma once

#include "MeowPCH.h"
#include <Meow/Core.h>

class MEOW_API Texture
{
private:
	unsigned int m_TexID;
	const char* m_TexPath;
public:
	Texture(const char* texPath);

	inline unsigned int getTextureId() const { return m_TexID; }

	void bind() const;
	void unbind() const;
};