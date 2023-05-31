#include "Villager.h"
Villager::Villager() {
	this->name = "村民";
	DialogObject* opening = new DialogObject("今天天氣真不錯。");
	opening->addOptionalResponse("還好吧。");
	opening->addOptionalResponse("確實，天氣挺好的。");
	this->setOpeningDialog(opening);
	DialogObject* d1 = new DialogObject("是嘛?我覺得天氣挺好的。");

	DialogObject* d2 = new DialogObject("對吧，天氣真的挺好的。話說能幫我一個忙嗎?");
	d2->addOptionalResponse("好。");
	d2->addOptionalResponse("我現在有點沒空，下次吧。");
	opening->addSubDialog(d1);
	opening->addSubDialog(d2);
	DialogObject* d3 = new DialogObject("幫我殺死十隻野狼，並帶來狼皮五個。");
	DialogObject* d4 = new DialogObject("好吧。");
	d2->addSubDialog(d3);
	d2->addSubDialog(d4);
}