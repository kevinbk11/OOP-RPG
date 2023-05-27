#include "AttackController.h"
AttackController* AttackController::controller = nullptr;
AttackController::AttackController() {}
AttackController* AttackController::getInstance()
{
	if (controller == nullptr) {
		controller = new AttackController();
	}
	return controller;
}
void AttackController::attack(Player* player, Mob* mob) {
	player->attack(mob);
}
void AttackController::choiceSkill(Player* player) {
	vector<Skill*>* skills = player->getSkills();
	cout << endl;
	for (int i=0; i<skills->size(); i++) {
		cout << i + 1 << "." << (*skills)[i]->skillName << endl;
	}
	int command;
	cout << "請輸入技能編號";
	cin >> command;
	player->setSkillChoice((*skills)[command-1]);
}