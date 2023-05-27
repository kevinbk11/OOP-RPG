#pragma once
#include<iostream>
#include"../../Utils/DamageObject.h"
#include "../GameObject.h"
class Mob : public GameObject
{
public:
	virtual void getAttack(DamageObject*) = 0;
	int getBasicDefenseValue();
	bool isLive();
protected:
	int hp;
	int mp;
	int basicDefenseValue = 0;
};

