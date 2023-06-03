#include "Item.h"
Item::Item(int count) {
	this->count = count;
}
Item::Item() {}
int Item::getCount() {
	return this->count;
}
void Item::drop(int count) {
	this->count -= count;
}
void Item::addCount(int count) {
	this->count += count;
}
void Item::printDetails() {
	cout << name << "x" << getCount() << "\n�D��y�z:" << describe << endl;
}
bool Item::use(Player* player) {
	cout << "�S���ĪG�C";
	return false;
}