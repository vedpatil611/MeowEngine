#include "MeowPCH.h"
#include "Texture.h"

#include <glad/glad.h>
#include <iostream>

#include "FreeImage/FreeImage.h"

namespace Meow
{
	Texture::Texture(const char* texPath)
		:m_TexPath(texPath), m_Width(0), m_Height(0), m_BPP(0)
	{
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		FIBITMAP* dib(0);
		BYTE* bits(0);

		fif = FreeImage_GetFileType(texPath, 0);
		if (fif == FIF_UNKNOWN)
			fif = FreeImage_GetFIFFromFilename(texPath);

		if (fif == FIF_UNKNOWN)
			throw std::exception("File type not supported");

		if (FreeImage_FIFSupportsReading(fif))
			dib = FreeImage_Load(fif, texPath);

		if (!dib)
			throw std::exception("Failed to load textures");

		FreeImage_FlipVertical(dib);

		bits = FreeImage_GetBits(dib);
		m_Width = FreeImage_GetWidth(dib);
		m_Height = FreeImage_GetHeight(dib);

		if (bits == 0 || m_Width == 0 || m_Height == 0)
			throw std::exception("Failed to load textures");

		GLCALL(glGenTextures(1, &m_TexID));
		GLCALL(glBindTexture(GL_TEXTURE_2D, m_TexID));
		
		GLCALL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));

		GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		//std::cout << FreeImage_GetBPP(dib) << std::endl << FreeImage_GetColorType(dib) << std::endl;
		
		GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_BGRA, GL_UNSIGNED_BYTE, bits));
		
		m_Slot = provideSlotNo++;

		FreeImage_Unload(dib);
	}

	Texture::~Texture()
	{
		GLCALL(glDeleteTextures(1, &m_TexID));
	}

	void Texture::setSlot(unsigned int slotNo)
	{
		m_Slot = slotNo;
	}

	void Texture::bind(unsigned int slot) const
	{
		GLCALL(glActiveTexture(GL_TEXTURE0 + slot));
		GLCALL(glBindTexture(GL_TEXTURE_2D, m_TexID));
	}

	void Texture::bind() const
	{
		GLCALL(glActiveTexture(GL_TEXTURE0 + m_Slot));
		GLCALL(glBindTexture(GL_TEXTURE_2D, m_TexID));
	}

	void Texture::unbind() const
	{
		GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
	}
}