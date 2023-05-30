#include "Fighter.h"
#include "../../../../../ControlCenter/ControlCenter.h"
Fighter::Fighter(string name):Player(name) {
	this->fullHp = 100;
	this->fullMp = 50;
	this->hp = fullHp;
	this->mp = fullMp;
	this->basicDamageValue = 35;
	this->basicDefenseValue = 10;
	this->setSkill(new NormalAttack());
}