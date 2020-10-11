#include "MeowPCH.h"
#include "Texture.h"

#include <glad/glad.h>

Texture::Texture(const char* texPath)
	:m_TexPath(texPath)
{
	GLCALL(glGenTextures(1, &m_TexID));
	GLCALL(glBindTexture(GL_TEXTURE_2D, m_TexID));


}

void Texture::bind() const
{
	GLCALL(glBindTexture(GL_TEXTURE_2D, m_TexID));
}

void Texture::unbind() const
{
	GLCALL(glBindTexture(GL_TEXTURE_2D, 0));
}
