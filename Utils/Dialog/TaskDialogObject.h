#pragma once
#include "DialogObject.h"
class TaskDialogObject :public DialogObject
{
public:
	TaskDialogObject(DialogObject*, int);
	TaskDialogObject *setSolved(string);
	TaskDialogObject *setNotSolved(string);
	TaskDialogObject* setAfterSolved(string);
	TaskDialogObject* setTask(Task*);
	TaskDialogObject* setEndOptoinalStringValue(string);
	TaskDialogObject* setOptionalStringValue(string);
	void execute(Player*, NPC*)override;
private:
	string solved;
	string notSolved;
	string afterSolved;
	string end;
	Task* task;
	DialogObject* parent;
};

