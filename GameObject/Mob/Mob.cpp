#include "Mob.h"
int Mob::getBasicDefenseValue() {
	return this->basicDefenseValue;
}
void Mob::getAttack(DamageObject* damageObject) {
	int damage = damageObject->getDamageValue();
	this->hp -= damage;
}
bool Mob::isLive() {
	return this->hp > 0;
}
int Mob::getHp() {
	return this->hp;
}
int Mob::getMp() {
	return this->mp;
}
void Mob::respawn() {
	this->hp = this->fullHp;
	this->mp = this->fullMp;
}