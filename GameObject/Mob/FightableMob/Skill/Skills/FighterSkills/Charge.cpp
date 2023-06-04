#include "Charge.h"
#include "../../SkillEffect/SkillEffects/PowerEffect.h"
Charge::Charge() {
	this->skillName = "蓄力";
}
void Charge::execute(FightableMob* caster, Mob* target) {
	PowerEffect* effect = new PowerEffect(2.2);
	if (caster->getMp() >= 25) {
		if (!(caster->effectState & effect->effectState)) {
			cout << "\n攻擊力上升了!!\n";
			this->addEffect(effect);
			this->executeEffect(caster);
			caster->addMp(-25);
		}
		else {
			cout << "\n攻擊力已經提升了。\n";
			delete effect;
		}
	}
	else {
		cout << "\n魔力不足，使用失敗!!。\n";
	}
}
