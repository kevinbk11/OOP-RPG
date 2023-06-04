#include "Task1.h"
Task1::Task1() {
	this->name = "¸É¥RÂ³­¹";
	this->requireItems = {
		{"¥Í½Þ¦×",5},
	};
	this->prize->exp = 50;
	this->prize->money = 100;
	this->prize->items.push_back(new WoodSword(1));
	this->prize->items.push_back(new LeatherArmor(1));
}