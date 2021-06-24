#include <vector>

namespace Meow
{
	class TextureArray
	{
	private:
		std::vector<class Texture*> m_Array;
	public:
		TextureArray();
		TextureArray(const char* path);
		~TextureArray();
	};
}

