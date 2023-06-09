#pragma once
#include<string>
#include "../Skill/SkillEffect/SkillEffect.h"
class FightableMob;
class Mob;
class SkillEffect;

class Skill
{
public:
	
	string skillName;
	void addEffect(SkillEffect*);
	void executeEffect(Mob*);
	virtual void execute(FightableMob*, Mob*);
private:
	vector<SkillEffect*> effects;
};

