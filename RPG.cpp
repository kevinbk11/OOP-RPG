// RPG.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "main.h"
using namespace std;
int main()
{
    GameController* gameController = ControlCenter::getInstance<GameController>();
    cout << "請輸入你的角色名字。\n";
    string name;
    cin >> name;
    /*cout << "請輸入你的職業代碼，1為戰士，2為法師。\n";
    cin >> command;*/
    CreateHeroController* creater = nullptr;
    Player* player=nullptr;
    creater = ControlCenter::getInstance<CreateHeroController>();
    player = creater->createPlayer(name, 1);
    system("cls");
    gameController->gameStart(player);

}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
