#include "MapLinker.h"
void MapLinker::link(vector<Map*> maps) {
	for (int i = 0; i < maps.size() - 1; i++) {
		maps[i]->setNextMap(maps[i + 1]);
		maps[i+1]->setPreviousMap(maps[i]);
	}
}