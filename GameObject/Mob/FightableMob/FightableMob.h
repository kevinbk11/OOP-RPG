#pragma once
#include "../Mob.h"
#include "../Fightable.h"
#include "../../../Utils/DamageObject.h"
class FightableMob :public Mob,public Fightable
{
public:

	virtual void attack(FightableMob*);
	virtual void getAttack(DamageObject* damageObject);
	int getBasicDamageValue();
	int getBasicDefenseValue();
protected:
	int basicDamageValue = 0;
	int basicDefenseValue = 0;
};

