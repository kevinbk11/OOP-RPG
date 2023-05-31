#pragma once
#include "../Enemy.h"
class Wolf :public Enemy
{
public:
	Wolf();
	void setBootyItems()override;
	void setSkillChoice();
};

