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
	cout << npc->name<<":" << this->sentence << endl << endl;
	if (this->disconnectPoint != nullptr) {
		if (this->forReplaceDialog->haveTask)this->forReplaceDialog->execute(player,npc);//為了接任務
		this->setOptionalDialog();
		return;
	}
	if (this->nextState.size() > 0) {
		cout << "請輸入你要回答的句子代號。\n";
		for (int i = 0; i < this->respond.size(); i++) {
			cout << i + 1 << "." << this->respond[i] << endl;
		}
		int choice;
		cin >> choice;
		cout << player->name << ":" << this->respond[choice - 1] << endl << endl;
		this->nextState[choice - 1]->execute(player, npc);
	}
}

void DialogObject::setDisconnectPoint(DialogObject* connectPoint,DialogObject* dialog,int index) {
	this->disconnectPoint = connectPoint;
	this->forReplaceDialog = dialog;
	this->pathIndex = index;
}
void DialogObject::setOptionalDialog() {
	delete this->disconnectPoint->nextState[this->pathIndex - 1];
	this->disconnectPoint->nextState[this->pathIndex-1] = this->forReplaceDialog;
}