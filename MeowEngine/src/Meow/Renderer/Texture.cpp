#include "MeowPCH.h"
#include <Meow/Renderer/Texture.h>

#include <glad/glad.h>
#include <iostream>
#include <stdexcept>
#include <stb_image.h>

namespace Meow
{
	Texture::Texture(const char* texPath)
		:m_TexPath(texPath), m_Width(0), m_Height(0), m_BPP(0)
	{
		m_Bits = stbi_load(texPath, &m_Width, &m_Height, &m_BPP, 0);
		if (!m_Bits)
		{
			printf("Failed to find tex file\n");
			throw std::runtime_error("Failed to find texture");
		}

		glGenTextures(1, &m_TexID);
		glBindTexture(GL_TEXTURE_2D, m_TexID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Bits);
		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);
		
		stbi_image_free(m_Bits);
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

	void Texture::unbind() const
	{
		GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
	}
}
