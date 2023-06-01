#pragma once
#include "../GameObject/Task/Task.h"
class TaskProcessor
{
public:
	static void update(vector<Task*>,string);
	static bool check(Task*);
	static bool check(Task*,Item);
};

