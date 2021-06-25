#include <vector>

namespace Meow
{
	class TextureArray
	{
	public:
		using iterator = std::vector<class Texture*>::iterator;
	private:
		std::vector<class Texture*> m_Array;
	public:
		TextureArray();
		TextureArray(const char* path);
		~TextureArray();

		unsigned int size() const;
		class Texture*& operator[](int index);

		iterator begin();
		iterator end();
	};
}

