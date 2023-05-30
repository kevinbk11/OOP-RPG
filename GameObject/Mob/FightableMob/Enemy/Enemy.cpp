#include "Enemy.h"
Booty* Enemy::dropBooty() {
	booty->exp = this->exp;
	booty->items = this->items;
	booty->money = this->money;
	return booty;
}