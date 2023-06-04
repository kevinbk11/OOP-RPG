#include "WoodSword.h"
WoodSword::WoodSword(int count):Weapon(count) {
	this->name = "木劍";
	this->describe = "一把堪用的木劍。";
	this->damageValue = 10;
}
