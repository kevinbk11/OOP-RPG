// RPG.cpp : ���ɮץ]�t 'main' �禡�C�{���|��ӳB�}�l����ε�������C
//

#include "main.h"
using namespace std;
int main()
{
    cout << "��J0���Ыب���A��J1��Ū�ɡC\n";
   
    int command;
    cin >> command;
    GameController* gameController = ControlCenter::getInstance<GameController>();
    switch (command) 
    {
        case 0: {
            cout << "�п�J�A������W�r�C\n";
            string name;
            cin >> name;
            cout << "�п�J�A��¾�~�N�X�A1���Ԥh�A2���k�v�C\n";
            cin >> command;
            CreateHeroController* creater = nullptr;
            Player* player=nullptr;
            creater = ControlCenter::getInstance<CreateHeroController>();
            player = creater->createPlayer(name, command);
            system("cls");
            gameController->gameStart(player);
            break;
        }
        case 1: {
            gameController->gameStart(nullptr);
            break;
        }
    }
}

// ����{��: Ctrl + F5 �� [����] > [�Ұʦ�������] �\���
// �����{��: F5 �� [����] > [�Ұʰ���] �\���

// �}�l�ϥΪ�����: 
//   1. �ϥ� [����`��] �����A�s�W/�޲z�ɮ�
//   2. �ϥ� [Team Explorer] �����A�s�u���l�ɱ���
//   3. �ϥ� [��X] �����A�Ѿ\�իؿ�X�P��L�T��
//   4. �ϥ� [���~�M��] �����A�˵����~
//   5. �e�� [�M��] > [�s�W����]�A�إ߷s���{���X�ɮסA�άO�e�� [�M��] > [�s�W�{������]�A�N�{���{���X�ɮ׷s�W�ܱM��
//   6. ����n�A���}�Ҧ��M�׮ɡA�Ыe�� [�ɮ�] > [�}��] > [�M��]�A�M���� .sln �ɮ�
