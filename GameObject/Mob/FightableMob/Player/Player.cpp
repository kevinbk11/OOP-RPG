#include "Player.h"
Player::Player(string name) {
	this->name = name;
	this->hp = 500;
	this -> mp = 500;
	this->basicDamageValue = 35;
	this->basicDefenseValue = 20;
}
void Player::attack(FightableMob* mob) {
	cout << "ª±®a"<<this->name<<"µo°Ê§ðÀ»\n";
	FightableMob::attack(mob);
	
}
void Player::getAttack(DamageObject* damageObject) {
	FightableMob::getAttack(damageObject);
	cout << "£«£«£«£«ªü";
}




