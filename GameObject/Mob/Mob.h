#pragma once
#include<iostream>
#include"../../Utils/DamageObject.h"
#include "../GameObject.h"
#include <vector>
class SkillEffect;
class Mob : public GameObject
{
public:
	int effectState=0;
	virtual void getAttack(DamageObject*) = 0;
	float getBasicDefenseValue();
	bool isLive();
	int getHp();
	int getMp();
	void addHp(int);
	void addMp(int);
	vector<SkillEffect*> selfEffect;
	virtual void respawn();
protected:
	int hp;
	int mp;
	int fullHp;
	int fullMp;
	float basicDefenseValue = 0;
	void initHp(int);
	void initMp(int);
	void initDefenseValue(float);

};

