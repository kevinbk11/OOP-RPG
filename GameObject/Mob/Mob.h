#pragma once
#include<iostream>
#include"../../Utils/DamageObject.h"
#include "../GameObject.h"
using namespace std;
class Mob : public GameObject
{
public:
	virtual void getAttack(DamageObject*) = 0;
protected:
	int hp;
	int mp;
};

