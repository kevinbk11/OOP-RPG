#pragma once
#include<string>
#include "../Skill/SkillEffect/SkillEffect.h"
class FightableMob;
class Mob;
class SkillEffect;

class Skill
{
public:
	
	std::string skillName;
	void addEffect(SkillEffect*);
	void executeEffect(FightableMob*, Mob*);
	virtual void execute(FightableMob*, Mob*);
private:
	vector<SkillEffect*> effects;
};

