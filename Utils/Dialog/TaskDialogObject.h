#pragma once
#include "DialogObject.h"
class TaskDialogObject :public DialogObject
{
public:
	TaskDialogObject(Task*);
	TaskDialogObject *setSolved(string);
	TaskDialogObject *setNotSolved(string);
	TaskDialogObject* setAfterSolved(string);
	TaskDialogObject* setEndOptionalStringValue(string);
	TaskDialogObject* setNextDialogObject(DialogObject*);
	void execute(Player*, NPC*)override;
private:
	string solved;
	string notSolved;
	string afterSolved;
	string end;
	Task* task;
	DialogObject* nextDialogObject;
};

