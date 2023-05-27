#pragma once
#include "../Mob.h"
#include "../Fightable.h"
#include "../../../Utils/DamageObject.h"
#include "Player/Skill/Skill.h"
#include <vector>
class Skill;
class FightableMob :public Mob,public Fightable
{
public:
	FightableMob();
	virtual void attack(Mob*);
	virtual void getAttack(DamageObject* damageObject);
	int getBasicDamageValue();
	int getBasicDefenseValue();
	vector<Skill*>* getSkills();
	void setSkill(Skill*);
	friend class SkillEffect;
protected:
	int basicDamageValue = 0;
	vector<Skill*>* skills = new vector<Skill*>();
};

