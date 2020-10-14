#include "MeowPCH.h"
#include "Texture.h"

#include <glad/glad.h>
#include <stb_image/stb_image.h>

#include <iostream>

namespace Meow
{
	Texture::Texture(const char* texPath)
		:m_TexPath(texPath), m_Width(0), m_Height(0), m_BPP(0)
	{
		stbi_set_flip_vertically_on_load(1);
		unsigned char * imageBuffer = stbi_load(texPath, &m_Width, &m_Height, &m_BPP, 4);
		if (stbi_failure_reason())
			std::cout << stbi_failure_reason() << std::endl;

		GLCALL(glGenTextures(1, &m_TexID));
		GLCALL(glBindTexture(GL_TEXTURE_2D, m_TexID));

		GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageBuffer));
		
		if (imageBuffer)
			stbi_image_free(imageBuffer);
	}

	Texture::~Texture()
	{
		GLCALL(glDeleteTextures(1, &m_TexID));
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