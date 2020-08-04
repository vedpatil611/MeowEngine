#pragma once

#include <Meow.h>

class MeowApplication: public Meow::Application
{
private:
	
public:
	MeowApplication() {}
	~MeowApplication() {}
	
	void Run() override;
};

