#include <vector>
#include <unordered_map>
#include <string>

namespace Meow
{
	class TextureArray
	{
	public:
		using iterator = std::unordered_map<std::string, class Texture*>::iterator;
	private:
		std::vector<std::string> m_Keys;
		std::unordered_map<std::string, class Texture*> m_Texs;
	public:
		TextureArray();
		TextureArray(const char* path);
		~TextureArray();

		unsigned int size() const;
		class Texture*& operator[](const char* key);

		iterator begin();
		iterator end();
	};
}

