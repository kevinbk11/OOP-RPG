#include "Enemy.h"
Booty* Enemy::dropBooty() {
	Booty *booty = new Booty();
	booty->exp = this->exp;
	booty->items = this->items;
	booty->money = this->money;
	return booty;
}