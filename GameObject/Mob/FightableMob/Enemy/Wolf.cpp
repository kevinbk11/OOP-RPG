#include "Wolf.h"
#include "../Skill/Skills/EnemySkills/Bite.h"
Wolf::Wolf() {
	this->name = "³¥¯T";
	this->fullHp = 100;
	this->fullMp = 0;
	this->hp = fullHp;
	this->mp = fullMp;
	this->basicDamageValue = 25;
	this->basicDefenseValue = 15;
}
void Wolf::setSkillChoice() {
	this->skillChoice = Bite();
}
