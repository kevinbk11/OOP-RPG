#include "DamageCalculator.h"
int DamageCalculator::calculate(FightableMob* m1, Mob* m2) {
	int res;
	res = m1->getBasicDamageValue() - m2->getBasicDefenseValue();
	return res;
}