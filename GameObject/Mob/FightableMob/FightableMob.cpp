#include "FightableMob.h"
FightableMob::FightableMob() {
}
int FightableMob::getBasicDamageValue() {
	return this->basicDamageValue;
}
int FightableMob::getBasicDefenseValue() {
	return this->basicDefenseValue;
}
void FightableMob::attack(Mob* enemy) {

}
void FightableMob::getAttack(DamageObject* damageObject) {
	cout << "怪物" << this->name << "被打了"<<damageObject->getDamageValue()<<"傷害。\n";
	Mob::getAttack(damageObject);
}
vector<Skill*>* FightableMob::getSkills() {
	return this->skills;
}
void FightableMob::setSkill(Skill* skill) {
	this->skills->push_back(skill);
}