#pragma once

#include <Meow/Core.h>
#include <Meow/Renderer/SpriteSheet.h>
#include <unordered_map>

typedef bool(*StateChangeFn)();

namespace Meow 
{
	struct StateData
	{
		int state;
		SpriteSheet* spriteSheet;
		StateChangeFn fn;
	};
	
	class MEOW_API StateMachine
	{
	private:
		int currentState;
		std::unordered_map<int, StateData*> map;
	public:
		StateMachine();
		~StateMachine();
	
		void addState(const StateData* state);
		void setCurrentState(int newState);
	};
}