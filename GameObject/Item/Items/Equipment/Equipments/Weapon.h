#pragma once
#include "../../../Item.h"
#include "../Wearable.h"
class Player;
class Item;
class Wearable;
class Weapon:public Item,public Wearable
{
public:
	Weapon(int count);
	void attachTo(Player*);
	void detachTo(Player*);
	int damageValue;
	bool use(Player*);
	string getName() {
		return this->name;
	}
protected:
	void showMessage(WearType type);
};

