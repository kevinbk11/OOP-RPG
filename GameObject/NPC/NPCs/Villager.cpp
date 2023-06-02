#include "Villager.h"
#include "../../../Utils/Dialog/TaskDialogObject.h"
#include "../../Task/Tasks/Task1.h"
Villager::Villager() {
	this->name = "村民";
	DialogObject* opening = new DialogObject("今天天氣真不錯。");
	this->setOpeningDialog(opening);
	opening->addOptional("我覺得還好。", "是嘛，我覺得不錯呀，風和日麗的。");
	auto dialog = opening->addOptional("確實。", "對呀，不過我想請你幫我一個忙")
		->addOptional("什麼忙?", "幫我殺死5匹野狼，之後帶來5個狼皮。");


	TaskDialogObject* taskDialog1 = (new TaskDialogObject(new Task1()))
		->setSolved("謝謝，真是太感激你了，這是給你的報酬。")
		//->setAfterSolved("其實還是有一點，能再多殺幾匹嗎?") 如果之後沒有任務則需要設定AfterSolved
		//如果任務的話，在其子對話設定要顯示的內容
		->setNotSolved("謝謝妳的幫忙，但可以的話希望能在多殺死幾匹野狼。")
		->setEndOptionalStringValue("最近村內還有傷亡事件嗎?");
	dialog->addOptional("為什麼要這麼做?", "因為狼群不斷的在傷害我們的居民，希望你能幫這個忙。")
		->addOptional("好的，我來幫忙。", "謝謝，麻煩你了!!")
		->setDisconnectPoint(opening,taskDialog1,2);

	dialog->addOptional("抱歉，我有點忙，下次吧。", "好吧。");

	dialog->addOptional("沒問題!!", "謝謝!真是太感謝了!")
		->setDisconnectPoint(opening, taskDialog1, 2);

	TaskDialogObject* taskDialog2 = (new TaskDialogObject(new Task1()))
		->setSolved("謝謝，真是太感激你了，這是給你的報酬，這次看起來真的清靜了。")
		->setAfterSolved("已經沒有了，謝謝。")
		->setNotSolved("謝謝妳的幫忙，但可以的話希望能在多殺死幾匹野狼。")
		->setEndOptionalStringValue("最近村內還有傷亡事件嗎?");

	DialogObject* afterTask1 = new DialogObject("其實還是有一點，能再多殺幾匹嗎?");
	afterTask1->addOptional("可以啊", "再次謝謝!")->setDisconnectPoint(opening,taskDialog2,2);
	taskDialog1->setNextDialogObject(afterTask1);


}