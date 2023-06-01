#include "TaskDialogObject.h"
TaskDialogObject::TaskDialogObject(DialogObject* parent,int index) {
	this->parent = parent;
	this->pathIndex = index-1;
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
TaskDialogObject* TaskDialogObject::setTask(Task* task) {
	this->task = task;
	return this;
}
TaskDialogObject* TaskDialogObject::setOptionalStringValue(string sentence) {
	this->sentence = sentence;
	return this;
}

TaskDialogObject* TaskDialogObject::setEndOptoinalStringValue(string sentence) {
	this->end = sentence;
	return this;
}
void TaskDialogObject::execute(Player* player,NPC* npc) {
	if (!this->task->isAccepted && !this->task->isSolved) {
		cout << "已接受「" << this->task->name << "」任務。\n\n";
		this->task->isAccepted = true;
		this->parent->respond[this->pathIndex] = this->sentence;
		player->acceptTask(this->task);	
	}
	else {
		if (this->task->isAccepted && this->task->isSolved)/*交差*/ {
			this->task->isAccepted = false;
			cout << this->solved << endl << endl;
			this->parent->respond[this->pathIndex] = this->end;
			player->getBooty(this->task->getPrize());
			player->solveTask(this->task);
			delete this->task->getPrize();
		}
		else if (!this->task->isAccepted && this->task->isSolved)/*已經交差過了*/ {
			cout << this->afterSolved << endl << endl;

		}
		else {
			cout << this->notSolved << endl << endl;
		}
	}

}