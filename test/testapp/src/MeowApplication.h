#pragma once

#include <Meow.h>
#include <Meow/Renderable/Sprite.h>
#include <Meow/Events/KeyEvent.h>

class MeowApplication: public Meow::Application
{
private:
	Rc<Meow::Sprite> cat = nullptr;
public:
	MeowApplication();
	~MeowApplication();
	
	void Run() override;
};

