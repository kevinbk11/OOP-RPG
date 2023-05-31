#include "DialogObject.h"
#include "../GameObject/Mob/FightableMob/Player/Player.h"
DialogObject::DialogObject(string sentence) {
	this->sentence = sentence;
}
void DialogObject::addSubDialog(DialogObject* dialog) {
	this->nextState.push_back(dialog);
}
void DialogObject::addOptionalResponse(string sentence) {
	this->respond.push_back(sentence);
}
void DialogObject::execute(Player* player,NPC* npc) {
	system("cls");
	cout << npc->name<<":" << this->sentence << endl << endl;
	if (this->nextState.size() > 0) {
		cout << "�п�J�A�n�^�����y�l�N���C\n";
		for (int i = 0; i < this->respond.size(); i++) {
			cout << i + 1 << "." << this->respond[i] << endl;
		}
		int choice;
		cin >> choice;
		cout << player->name << ":" << this->respond[choice-1] << endl << endl;
		this->nextState[choice-1]->execute(player, npc);
	}

}