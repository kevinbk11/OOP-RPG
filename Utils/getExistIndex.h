#pragma once
#include <vector>
template <typename T>
int getExistIndex(std::vector<T>container) {
	int command;
	do {
		cin >> command;
		if (command <= 0)break;
		if (command - 1 >= container.size()) {
			cout << "error";
			continue;
		}
		return command - 1;
	} while (true);
	return -1;
}