#pragma once
#include <string>
class DamageObject
{
private:
	int damage;
public:
	std::string type;
	DamageObject(int,int);
	int getDamageValue();
};

