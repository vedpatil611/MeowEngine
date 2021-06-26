#include <Meow/Core.h>

#include "Node.h"
#include <string>

namespace Meow
{
	class MEOW_API Level
	{
		private:
			std::string m_LevelName;
			Scene::Node* m_Root;
		public:
			Level() = default;
			~Level();

			void update(float delta);
			void render(float delta);
	};
} 
