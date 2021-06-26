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
			typedef void (Scene::Node::*NodeIteratorFunctionvf)(float);
			//using NodeIteratorFunctionvf = void (Meow::Scene::Node::*)(float);
		public:
			Level(const char* levelName);
			~Level();

			void update(float delta);
			void render(float delta);
		private:
			void iterateChildren(Scene::Node* node, float delta, NodeIteratorFunctionvf fn);
	};
}
