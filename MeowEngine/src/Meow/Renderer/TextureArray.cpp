#include "MeowPCH.h"
#include "TextureArray.h"

#include <algorithm>
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
				m_Keys.push_back(entry.path().stem().c_str());
				m_Texs.emplace(entry.path().stem().c_str(), new Texture(entry.path().c_str()));
			}
		}
	}

	TextureArray::TextureArray(const char* path)
	{
		for(auto& entry: std::filesystem::recursive_directory_iterator(path))
		{
			if(!entry.is_directory() && strcmp(entry.path().extension().c_str(), ".png") == 0)
			{	
				m_Keys.push_back(entry.path().stem().c_str());
				m_Texs[m_Keys.back()] = new Texture(entry.path().c_str());
			}
		}
	}

	TextureArray::~TextureArray()
	{
		for(auto [k, tex]: m_Texs)
			delete tex;
	}

	unsigned int TextureArray::size() const 
	{
		return m_Texs.size();
	}

	Texture*& TextureArray::operator[](const char* key)
	{
		return m_Texs[key];
	}

	TextureArray::iterator TextureArray::begin()
	{
		return m_Texs.begin();
	}

	TextureArray::iterator TextureArray::end()
	{
		return m_Texs.end();
	}
}
