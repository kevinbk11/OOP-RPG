#include "FightableMob.h"
FightableMob::FightableMob() {
}
float FightableMob::getBasicDamageValue() {
	return this->basicDamageValue;
}
float FightableMob::getBasicDefenseValue() {
	return this->basicDefenseValue;
}
void FightableMob::attack(Mob* mob) {
	this->executeSkill(this, mob);
}
void FightableMob::getAttack(DamageObject* damageObject) {
	cout << endl<< this->name << "受到了" <<damageObject->type<< damageObject->getDamageValue() << "點\n";
	Mob::getAttack(damageObject);
}
vector<Skill*> FightableMob::getSkills() {
	return this->skills;
}
void FightableMob::setSkill(Skill* skill) {
	this->skills.push_back(skill);
}
void FightableMob::setSkillChoice(Skill* skill) {
	this->skillChoice = skill;
}
void FightableMob::setSkillChoice() { }
void FightableMob::executeSkill(FightableMob* mob1, Mob* mob2) {
	cout << endl << this->name << "使用了" << this->skillChoice->skillName << "。" << endl;
	this->skillChoice->execute(mob1, mob2);
}
void FightableMob::initDamageValue(float value) {
	this->basicDamageValue = value;
}
void FightableMob::adjustDamageValue(int delta) {
	this->basicDamageValue += delta;
}
void FightableMob::adjustDefenseValue(int delta) {
	this->basicDefenseValue += delta;
}
void FightableMob::setDamageValue(int value) {
	this->basicDamageValue = value;
}
void FightableMob::setDefenseValue(int value) {
	this->basicDefenseValue = value;
}