#pragma once
#include<string>
#include "../../FightableMob.h"
class SkillEffect;
class Skill
{
public:
	std::string skillName;
private:
	SkillEffect* effect=nullptr;
};

