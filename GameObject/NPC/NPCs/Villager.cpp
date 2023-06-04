﻿#include "Villager.h"
#include "../../../Utils/Dialog/TaskDialogObject.h"
#include "../../Task/Tasks/Task1.h"
#include "../../Task/Tasks/Task2.h"
Villager::Villager() {
	this->name = "村民";

	TaskDialogObject* taskDialog1 = (new TaskDialogObject(new Task1()))
		->setSolved("謝謝，真是太感激你了，這是給你的武器和裝甲，可以讓你在旅途中使用(打開裝備背包穿上道具)。")
		->setAfterSolved("...") //如果之後沒有任務則需要設定AfterSolved
		//如果任務的話，在其子對話設定要顯示的內容
		->setNotSolved("這點分量的豬肉可能不太夠村裡的人吃，能再多狩獵一點嗎?。")
		->setEndOptionalStringValue("確實");

	TaskDialogObject* taskDialog2 = (new TaskDialogObject(new Task2()))
		->setSolved("謝謝，你真是太厲害了!你是我們的英雄!")
		->setAfterSolved("沒有了，多虧了你，現在村民們可以放心地去森林蒐集食物了，謝謝你!")
		->setNotSolved("感覺還聽的到狼叫聲...。")
		->setEndOptionalStringValue("還有什麼要幫忙的嗎?");

	DialogObject* opening = new DialogObject("嗨，今天天氣還真不錯");
	this->setOpeningDialog(opening);
	DialogObject* d1 = opening->addOptional("是啊", "話說，最近村內食物有點短缺，能幫我們蒐集一些食物嗎?");

	d1->addOptional("抱歉，我有點忙。", "好吧...。");
	d1->addOptional("好啊，沒問題!", "太感謝您了，大概需要5份生豬肉，在旁邊的草原上就有野豬了。")
		->setDisconnectPoint(opening, taskDialog1, 1);

	DialogObject* afterTask1 = new DialogObject("不好意思，森林裡面的狼群最近在不斷的作亂，能在幫我們一下嗎?，這次需要殺死5匹野狼，之後帶來5個狼皮");
	
	afterTask1->addOptional("有點太困難了...可能要另請高人", "好吧，但還是謝謝你。");
	afterTask1->addOptional("沒問題，交給我!", "太謝謝你了!!")
		->setDisconnectPoint(opening, taskDialog2, 1);
	taskDialog1->setNextDialogObject(afterTask1);
	/*/auto dialog = opening->addOptional("確實。", "對呀，不過我想請你幫我一個忙")
		->addOptional("什麼忙?", "幫我殺死5匹野狼，之後帶來5個狼皮。");



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
	taskDialog1->setNextDialogObject(afterTask1);*/


}