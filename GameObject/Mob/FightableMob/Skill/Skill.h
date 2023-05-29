#pragma once
#include<string>
class Player;
class Mob;
class SkillEffect;
class Skill
{
public:
	std::string skillName;
	void setSkillEffect(SkillEffect*);
	void executeEffect(Player*,Mob*);
private:
	SkillEffect* effect=nullptr;
};

