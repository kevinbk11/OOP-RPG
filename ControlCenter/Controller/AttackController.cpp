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
	/*vector<Skill>* skills = player->getSkills();
	for (int i = 0; i < skills->size(); i++) {
		cout << i + 1 << ".";
	}*/
}