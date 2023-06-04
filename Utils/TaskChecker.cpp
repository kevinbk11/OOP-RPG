
#include "TaskChecker.h"
void TaskProcessor::update(vector<Task*> tasks, string monsterName) {
	for (auto task : tasks) {
		if (task->requireMonster.count(monsterName)) {
			task->requireMonster[monsterName]--;
			continue;
		}
	}
}
bool TaskProcessor::check(Task* task) {
	for (auto& it : task->requireMonster) {
		if (it.second > 0)return false;
	}
	return true;
}
bool TaskProcessor::check(Task* task, Item item) {
	for (auto& it : task->requireItems) {
		if (it.second>item.getCount() || !task->requireItems.count(item.name))return false;
	}
	if (check(task) && !task->isSolved) {
		return true;
	}
	else return false;
}