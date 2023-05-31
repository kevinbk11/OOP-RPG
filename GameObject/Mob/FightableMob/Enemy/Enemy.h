#pragma once
#include "../FightableMob.h"
#include "../../../Item/Items/AllItems.h"
#include "../../../../Utils/Booty.h"
class Booty;
class Item;
class FightableMob;
class Enemy:public FightableMob
{
public:
	Booty *dropBooty();
protected:
	Booty* booty = new Booty();
	virtual void setBootyItems()=0;
};

