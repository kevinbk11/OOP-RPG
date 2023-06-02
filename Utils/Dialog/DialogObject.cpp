#include "DialogObject.h"
#include "../../GameObject/Mob/FightableMob/Player/Player.h"
DialogObject::DialogObject(string sentence) {
	this->sentence = sentence;
}
DialogObject::DialogObject(){}
DialogObject* DialogObject::addSubDialog(DialogObject* dialog) {
	this->nextState.push_back(dialog);
	return dialog;
}
DialogObject* DialogObject::addOptional(string sentence,string respond) {
	this->respond.push_back(sentence);
	DialogObject* subDialog = new DialogObject(respond);
	this->addSubDialog(subDialog);
	return subDialog;
}
void DialogObject::execute(Player* player,NPC* npc) {
	system("cls");
	if(this->sentence!="")cout << npc->name << ":" << this->sentence << endl << endl;
	if (this->disconnectPoint != nullptr) {
		if (this->forReplaceDialog->haveTask)this->forReplaceDialog->execute(player,npc);//���F������
		this->setOptionalDialog();
		return;
	}
	if (this->nextState.size() > 0) {
		cout << "�п�J�A�n�^�����y�l�N���C\n";
		for (int i = 0; i < this->respond.size(); i++) {
			cout << i + 1 << "." << this->respond[i] << endl;
		}
		int choice;
		while (cin >> choice) {
			try {
				this->nextState.at(choice - 1);
				break;
			}
			catch (exception){
				cout << "�п�J���T���N���C\n";
				continue;
			}
		}

		if(!this->nextState[choice - 1]->haveTask)cout << player->name << ":" << this->respond[choice - 1] << endl << endl;
		this->nextState[choice - 1]->execute(player, npc);
	}
}

void DialogObject::setDisconnectPoint(DialogObject* connectPoint,DialogObject* dialog,int index) {
	this->disconnectPoint = connectPoint;
	this->forReplaceDialog = dialog;
	this->pathIndex = index;
	this->forReplaceDialog->parent = connectPoint;
	this->forReplaceDialog->pathIndex = index;
}
void DialogObject::setOptionalDialog() {
	this->disconnectPoint->nextState[this->pathIndex - 1] = this->forReplaceDialog;
}