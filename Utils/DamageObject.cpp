#include "DamageObject.h"
DamageObject::DamageObject(int damage) {
	this->damage = damage;
}
int DamageObject::getDamageValue() {
	return this->damage;
}