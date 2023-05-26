#include "FightableMob.h"
#include "../../../Utils/Calculator/DamageCalculator.h"
int FightableMob::getBasicDamageValue() {
	return this->basicDamageValue;
}
int FightableMob::getBasicDefenseValue() {
	return this->basicDefenseValue;
}
void FightableMob::attack(FightableMob* enemy) {
	DamageCalculator *calculator = new DamageCalculator();
	DamageObject damage = calculator->calculate(this, enemy);
	enemy->getAttack(&damage);
}
void FightableMob::getAttack(DamageObject* damageObject) {
	cout << "�Ǫ�" << this->name << "�Q���F"<<damageObject->getDamageValue()<<"�ˮ`�C\n";
	Mob::getAttack(damageObject);
}