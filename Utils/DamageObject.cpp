#include "DamageObject.h"
#include<iostream>
DamageObject::DamageObject(int damage,int typeID) {
	this->damage = damage;
	switch(typeID){
		case 0:
			this->type = "´¶³q¶Ë®`";
			break;
		case 1:
			this->type = "¿U¿N¶Ë®`";
			break;
	}
}
int DamageObject::getDamageValue() {
	return this->damage;
}