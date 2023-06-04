#include "Charge.h"
#include "../../SkillEffect/SkillEffects/PowerEffect.h"
Charge::Charge() {
	this->skillName = "�W�O";
}
void Charge::execute(FightableMob* caster, Mob* target) {
	PowerEffect* effect = new PowerEffect(2.2);
	if (caster->getMp() >= 25) {
		if (!(caster->effectState & effect->effectState)) {
			cout << "\n�����O�W�ɤF!!\n";
			this->addEffect(effect);
			this->executeEffect(caster);
			caster->addMp(-25);
		}
		else {
			cout << "\n�����O�w�g���ɤF�C\n";
			delete effect;
		}
	}
	else {
		cout << "\n�]�O�����A�ϥΥ���!!�C\n";
	}
}
