#include "DamageObject.h"
#include<iostream>
DamageObject::DamageObject(int damage,int typeID) {
	this->damage = damage;
	switch(typeID){
		case 0:
			this->type = "���q�ˮ`";
			break;
		case 1:
			this->type = "�U�N�ˮ`";
			break;
	}
}
int DamageObject::getDamageValue() {
	return this->damage;
}