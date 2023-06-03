#include "AttackController.h"
#include "../../Utils/getExistIndex.h"
#include "../../GameObject/Mob/FightableMob/Skill/SkillEffect/SkillEffect.h"
AttackController* AttackController::controller = nullptr;
AttackController* AttackController::getInstance()
{
	if (controller == nullptr) {
		controller = new AttackController();
	}
	return controller;
}
AttackController::AttackController() {}
void AttackController::attack(FightableMob* mob1, Mob* mob2) {
	mob1->attack(mob2);
	this->executeDamageCalculate(mob1, mob2);
}
void AttackController::executeDamageCalculate(FightableMob* mob1, Mob* mob2) {
	vector<SkillEffect*>* effects = &mob2->selfEffect;
	for (int i = 0; i < effects->size(); i++) {
		SkillEffect* effect = effects->at(i);
		float damage = effect->calculateDamage(mob1, mob2);
		effect->execute(damage, mob2);
		if (effect->times == 0) {
			if ((effect->effectState & mob2->effectState)) {
				mob2->effectState -= effect->effectState;
			}
			effects->erase(effects->begin() + i);
			delete effect;
			i--;
		}
	}
}
void AttackController::choiceSkill(Player* player) {
	vector<Skill*> skills = player->getSkills();
	cout << endl;
	for (int i=0; i<skills.size(); i++) {
		cout << i + 1 << "." << skills[i]->skillName << endl;
	}
	cout << endl;
	int command;
	cout << "請輸入技能編號。 \n";
	command = getExistIndex(skills);
	player->setSkillChoice(skills[command]);

}
void AttackController::choiceSkill(FightableMob* mob) {
	mob->setSkillChoice();
}