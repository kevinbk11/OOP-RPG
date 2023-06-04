#include "TaskDialogObject.h"
#include "../TaskChecker.h"
TaskDialogObject::TaskDialogObject(Task* task) {
	this->task = task;
	this->sentence = "�������:"+this->task->name;
	this->nextDialogObject = nullptr;
	this->haveTask=true;
}
TaskDialogObject* TaskDialogObject::setAfterSolved(string sentence) {
	this->afterSolved = sentence;
	return this;
}
TaskDialogObject* TaskDialogObject::setNotSolved(string sentence) {
	this->notSolved = sentence;
	return this;
}
TaskDialogObject* TaskDialogObject::setSolved(string sentence) {
	this->solved = sentence;
	return this;
}

TaskDialogObject* TaskDialogObject::setEndOptionalStringValue(string sentence) {
	this->end = sentence;
	return this;
}
TaskDialogObject* TaskDialogObject::setNextDialogObject(DialogObject* dialog) {
	this->nextDialogObject = dialog;
	return this;
}
void TaskDialogObject::execute(Player* player,NPC* npc) {
	if (!this->task->isAccepted && !this->task->isSolved) {
		cout << "�w�����u" << this->task->name << "�v���ȡC\n\n";
		this->task->isAccepted = true;
		this->parent->respond[this->pathIndex-1] = this->sentence;
		player->acceptTask(this->task);
		for (int type = 0; type < 2; type++) {
			vector<vector<Item*>> bag = player->getBag();
			for (auto item : bag[type]) {
				if (TaskProcessor::check(this->task, *item)) {
					cout << "\n���ȡu" << this->task->name << "�v�����C\n\n";
					this->task->isSolved = true;
				}
			}
		}
	}
	else {
		system("cls");
		cout << npc->name << ":";
		if (this->task->isAccepted && this->task->isSolved)/*��t*/ {
			this->task->isAccepted = false;
			cout << this->solved << endl << endl;
			this->parent->respond[this->pathIndex-1] = this->end;
			player->getBooty(this->task->getPrize());
			player->solveTask(this->task,0);
			delete this->task->getPrize();
		}
		else if (!this->task->isAccepted && this->task->isSolved)/*�w�g��t�L�F*/ {
			cout << this->afterSolved << endl << endl;
			if (this->nextDialogObject != nullptr)this->nextDialogObject->execute(player, npc);
		}
		else {
			cout << this->notSolved << endl << endl;
		}
	}

}