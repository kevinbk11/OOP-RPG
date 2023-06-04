#include "LeatherArmor.h"
LeatherArmor::LeatherArmor(int count):Armor(count) {
	this->name = "皮革裝甲";
	this->defenseValue = 12;
	this->describe = "雖然是皮革製的，但是還蠻強韌的。";
}