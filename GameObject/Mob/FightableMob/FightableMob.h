#pragma once
#include "../Mob.h"
#include "../Fightable.h"
#include "../../../Utils/DamageObject.h"
#include "../FightableMob/Skill/Skill.h"
#include <vector>
class Skill;
class FightableMob :public Mob,public Fightable
{
public:
	FightableMob();
	virtual void attack(Mob*);
	virtual void getAttack(DamageObject* damageObject);
	float getBasicDamageValue();
	float getBasicDefenseValue();
	vector<Skill*> getSkills();
	void setSkill(Skill*);
	virtual void setSkillChoice();
	void setSkillChoice(Skill*);
	void executeSkill(FightableMob*,Mob*);
	void adjustDamageValue(int delta);
	void adjustDefenseValue(int delta);
	void setDamageValue(int value);
	void setDefenseValue(int value);
	friend class SkillEffect;
protected:
	float basicDamageValue = 0;
	vector<Skill*> skills = vector<Skill*>();
	Skill* skillChoice;
	void initDamageValue(float);
};

