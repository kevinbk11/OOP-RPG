#pragma once
#include "../Mob/FightableMob/Enemy/Enemys/AllMonster.h"
#include "../Item/Items/AllItems.h"
#include <unordered_map>
class Task:public GameObject
{
public:
	bool isAccepted=false;
	bool isSolved=false;
	Booty* getPrize();
	unordered_map<string,int>requireItems;
	unordered_map<string,int> requireMonster;
protected:
	Booty* prize=new Booty();
};

