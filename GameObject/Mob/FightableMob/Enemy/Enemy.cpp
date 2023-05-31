#include "Enemy.h"
Booty* Enemy::dropBooty() {
	this->setBootyItems();
	return booty;
}