#include "Mob.h"
float Mob::getBasicDefenseValue() {
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
void Mob::addHp(int value) {
	this->hp = this->hp + value < this->fullHp ? this->hp + value : this->fullHp;
}
void Mob::addMp(int value) {
	this->mp = this->mp + value < this->fullMp ? this->mp + value : this->fullMp;
}
void Mob::initHp(int value) {
	this->fullHp = value;
	this->hp = fullHp;
}
void Mob::initMp(int value) {
	this->fullMp = value;
	this->mp = fullMp;
}
void Mob::initDefenseValue(float value) {
	this->basicDefenseValue = value;
}