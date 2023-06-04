#include "Task2.h"
Task2::Task2() {
	this->name = "À»°h¯T¸s";
	this->requireItems = {
		{"¯T¥Ö",5},
	};
	this->requireMonster = {
		{"³¥¯T",5},
	};
	this->prize->exp = 50;
	this->prize->money = 100;
	this->prize->items.push_back(new HealWater(10));
}