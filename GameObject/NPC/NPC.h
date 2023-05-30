#pragma once
#include "../GameObject.h"
class NPC : public GameObject
{
public:
	virtual void talk()=0;
};

