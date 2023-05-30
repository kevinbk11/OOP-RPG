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
	int getHp();
	int getMp();
	virtual void respawn();
protected:
	int hp;
	int mp;
	int fullHp;
	int fullMp;
	int basicDefenseValue = 0;
};

