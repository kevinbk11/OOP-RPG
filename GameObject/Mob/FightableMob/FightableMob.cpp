#include "FightableMob.h"
FightableMob::FightableMob() {
}
int FightableMob::getBasicDamageValue() {
	return this->basicDamageValue;
}
int FightableMob::getBasicDefenseValue() {
	return this->basicDefenseValue;
}
void FightableMob::attack(Mob* mob) {
	this->executeSkill(this, mob);
}
void FightableMob::getAttack(DamageObject* damageObject) {
	cout << endl<< this->name << "�Q���F" << damageObject->getDamageValue() << "�ˮ`�C\n";
	Mob::getAttack(damageObject);
}
vector<Skill*> FightableMob::getSkills() {
	return this->skills;
}
void FightableMob::setSkill(Skill* skill) {
	this->skills.push_back(skill);
}
void FightableMob::setSkillChoice(Skill skill) {
	this->skillChoice = skill;
}
void FightableMob::setSkillChoice() { }
void FightableMob::executeSkill(FightableMob* mob1, Mob* mob2) {
	cout << endl << this->name << "�ϥΤF" << this->skillChoice.skillName << "�C" << endl;
	this->skillChoice.executeEffect(mob1, mob2);
}