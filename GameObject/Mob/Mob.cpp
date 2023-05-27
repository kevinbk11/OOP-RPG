#include "Mob.h"
int Mob::getBasicDefenseValue() {
	return this->basicDefenseValue;
}
void Mob::getAttack(DamageObject* damageObject) {
	int damage = damageObject->getDamageValue();
	this->hp -= damage;
}
bool Mob::isLive() {
	return this->hp >= 0;
}