#include "Task1.h"
Task1::Task1() {
	this->name = "�ɥR³��";
	this->requireItems = {
		{"�ͽަ�",5},
	};
	this->prize->exp = 50;
	this->prize->money = 100;
	this->prize->items.push_back(new WoodSword(1));
	this->prize->items.push_back(new LeatherArmor(1));
}