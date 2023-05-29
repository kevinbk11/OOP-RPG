#include "Fighter.h"
Fighter::Fighter(string name):Player(name) {
	this->hp = 500;
	this->mp = 100;
	this->basicDamageValue = 35;
	this->basicDefenseValue = 20;
	this->setSkill(new NormalAttack());
}