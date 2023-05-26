#include "Mob.h"
void Mob::getAttack(DamageObject* damageObject) {
	int damage = damageObject->getDamageValue();
	this->hp -= damage;
}