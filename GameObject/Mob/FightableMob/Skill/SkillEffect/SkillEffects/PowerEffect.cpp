#include "PowerEffect.h"
#include <math.h>
PowerEffect::~PowerEffect() {
	if (myself->name != ""){
		myself->setDamageValue(this->originDamageValue);
	}
}
PowerEffect::PowerEffect(double magnification) {
	this->magnification = magnification;
	this->times = 2;//�]���I�񪺮ɭԷ|�Ӥ@�^�X
	this->effectState = int(STATE::CHARGED);
}
float PowerEffect::calculateDamage(FightableMob* mob1, Mob* mob2) {
	return 0.0;
}
void PowerEffect::execute(float dif, FightableMob* caster, Mob* target) {
	//�]���S���`����{�]�p�A�b�[�c�����O���N�Ҧ����ĪG�ᵹ���A�M������設�W���ĪG�p�ˮ`�οU�N
	//�o�ɭP�F���a���ۤv�I��[�j������A�Ĥ�|�����誺�ĪG
	//�ҥH�o�̪��a�ϥΤF�[�j�ۨ������O���ĪG�ɡA�ĪG�b���a���W�A�ӥѼĤH�Ӱ���o�qexecute
	//�ҥH�u���n�[�j���H�ϦӬOtarget�Ӥ��Ocaster�A�~�|�O���ۤv�[�����C
	//�S���ɶ��F�A�u��N���N��
	//�ӥB�o�q��ڤW�|�����⦸�A���V�|
	myself = dynamic_cast<FightableMob*>(target);

	if(this->times==2)this->originDamageValue = myself->getBasicDamageValue();//�N��Ĥ@���I��
	this->times--;
	myself->setDamageValue(myself->getBasicDamageValue() * this->magnification);


}