#pragma once
#include<string>
class FightableMob;
class Mob;
class SkillEffect;
class Skill
{
public:
	std::string skillName;
	void setSkillEffect(SkillEffect*);
	void executeEffect(FightableMob*, Mob*);
private:
	SkillEffect* effect;
};

