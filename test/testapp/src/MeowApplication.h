#pragma once

#include <Meow.h>
#include <Meow/Renderable/Sprite.h>
#include <Meow/Events/KeyEvent.h>

class MeowApplication: public Meow::Application
{
private:
	inline static Rc<Meow::Sprite> cat = nullptr;
public:
	MeowApplication();
	~MeowApplication();
	
	void Run() override;
private:
	static bool onKeyPressed(Meow::KeyPressedEvent& e);
};

