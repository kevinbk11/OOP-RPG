#pragma once
#include "../Enemy.h"
class Pig:public Enemy
{
public:	
	Pig();
	void setBootyItems()override;
	void setSkillChoice();
};

