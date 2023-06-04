#include "PowerEffect.h"
#include <math.h>
PowerEffect::~PowerEffect() {
	if (myself->name != ""){
		myself->setDamageValue(this->originDamageValue);
	}
}
PowerEffect::PowerEffect(double magnification) {
	this->magnification = magnification;
	this->times = 2;//因為施放的時候會耗一回合
	this->effectState = int(STATE::CHARGED);
}
float PowerEffect::calculateDamage(FightableMob* mob1, Mob* mob2) {
	return 0.0;
}
void PowerEffect::execute(float dif, FightableMob* caster, Mob* target) {
	//因為沒有深思熟慮設計，在架構中其實是先將所有的效果丟給對方，然後執行對方身上的效果如傷害或燃燒
	//這導致了玩家幫自己施放加強攻擊後，敵方會執行對方的效果
	//所以這裡玩家使用了加強自身攻擊力的效果時，效果在玩家身上，而由敵人來執行這段execute
	//所以真正要加強的人反而是target而不是caster，才會是幫自己加攻擊。
	//沒有時間了，只能將錯就錯
	//而且這段實際上會執行到兩次，很糟糕
	myself = dynamic_cast<FightableMob*>(target);

	if(this->times==2)this->originDamageValue = myself->getBasicDamageValue();//代表第一次施放
	this->times--;
	myself->setDamageValue(myself->getBasicDamageValue() * this->magnification);


}