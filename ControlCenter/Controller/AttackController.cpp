#include "AttackController.h"
AttackController* AttackController::controller = nullptr;
AttackController* AttackController::getInstance()
{
	if (controller == nullptr) {
		controller = new AttackController();
	}
	return controller;
}
AttackController::AttackController() {}
void AttackController::attack(Player* player, Mob* mob) {
	player->attack(mob);
}
void AttackController::choiceSkill(Player* player) {
	vector<Skill*>* skills = player->getSkills();
	cout << endl;
	for (int i=0; i<skills->size(); i++) {
		cout << i + 1 << "." << (*skills)[i]->skillName << endl;
	}
	cout << endl;
	int command;
	cout << "請輸入技能編號。 \n";
	cin >> command;
	player->setSkillChoice(*(*(skills))[command - 1]);
}
void AttackController::attack(FightableMob* mob, Player* player) {
	mob->attack(player);
}
void AttackController::choiceSkill(FightableMob* mob) {
	mob->setSkillChoice();
}