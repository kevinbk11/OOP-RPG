#pragma once
#include "../Item.h"
class HealWater :public Item
{
public:
	HealWater(int);
	bool use(Player*)override;
};

