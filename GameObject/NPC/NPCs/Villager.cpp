#include "Villager.h"
#include "../../../Utils/Dialog/TaskDialogObject.h"
#include "../../Task/Tasks/Task1.h"
Villager::Villager() {
	this->name = "村民";
	DialogObject* opening = new DialogObject("今天天氣真不錯。");
	this->setOpeningDialog(opening);
	opening->addOptional("還好吧。","是嘛?我覺得天氣挺好的。");
	DialogObject* d=opening->addOptional("確實，天氣挺好的。","對吧，天氣真的挺好的。話說能幫我一個忙嗎?");
	
	TaskDialogObject* taskDialog = new TaskDialogObject(opening,2);
	taskDialog
		->setSolved("謝謝你幫我們擊退了野狼!這個給你吧。")
		->setNotSolved("看起來還沒完成呀?再努力一下吧，謝謝你了。")
		->setAfterSolved("草原上少了許多狼，看來最近會安寧很多。")
		->setOptionalStringValue("我完成任務了!")
		->setEndOptoinalStringValue("確實，天氣不錯，最近還有野狼嗎?")
		->setTask(new Task1());
	d = d->addOptional("什麼忙?。", "幫我殺死五隻野狼，並帶來狼皮五個。");
	DialogObject* d1=d->addOptional("為什麼要這麼做?", "因為野狼破壞了附近的防禦措施，再不消滅牠們會很麻煩。");
	d1->addOptional("好吧。", "謝謝!")->setDisconnectPoint(opening,taskDialog,2);
	d1->addSubDialog(d->addOptional("我現在有點沒空，下次吧。", "好吧。"));
	d->addOptional("沒問題!", "太謝謝你了!!")->setDisconnectPoint(opening, taskDialog,2);
}