#include "FightableMob.h"
#include "../../../Utils/Calculator/DamageCalculator.h"
FightableMob::FightableMob() {}
int FightableMob::getBasicDamageValue() {
	return this->basicDamageValue;
}
int FightableMob::getBasicDefenseValue() {
	return this->basicDefenseValue;
}
void FightableMob::attack(Mob* enemy) {

}
void FightableMob::getAttack(DamageObject* damageObject) {
	cout << "�Ǫ�" << this->name << "�Q���F"<<damageObject->getDamageValue()<<"�ˮ`�C\n";
	Mob::getAttack(damageObject);
}
vector<Skill>* FightableMob::getSkills() {
	return this->skills;
}