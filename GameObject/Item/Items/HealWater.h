#pragma once
#include "../Item.h"
class HealWater :public Item
{
public:
	HealWater(int);
	virtual bool use(Player*)override;
};

