#include "LeatherArmor.h"
LeatherArmor::LeatherArmor(int count):Armor(count) {
	this->name = "皮甲裝甲";
	this->defenseValue = 3;
	this->describe = "有點破舊的裝甲。";
}