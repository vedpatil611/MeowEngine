#include "MeowPCH.h"
#include "TextureArray.h"

#include <filesystem>
#include <string.h>
#include <Meow/Renderer/Texture.h>

namespace Meow
{
	TextureArray::TextureArray()
	{
		for(auto& entry: std::filesystem::recursive_directory_iterator("./"))
		{
			if(!entry.is_directory() && strcmp(entry.path().extension().c_str(), ".png") == 0)
			{
				m_Array.push_back(new Texture(entry.path().c_str()));
			}
		}
	}

	TextureArray::TextureArray(const char* path)
	{
		for(auto& entry: std::filesystem::recursive_directory_iterator(path))
		{
			if(!entry.is_directory() && strcmp(entry.path().extension().c_str(), ".png") == 0)
			{
				m_Array.push_back(new Texture(entry.path().c_str()));
			}
		}
	}

	TextureArray::~TextureArray()
	{
		for(auto* tex: m_Array)
			delete tex;
	}
}
