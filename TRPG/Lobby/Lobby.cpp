#include "Lobby.h"

#include <iostream>

#include "../InputHelper.h"
#include "../Alchemy/AlchemyWorkShop.h"
#include "../Dungeon/Dungeon.h"
#include "../Inventroy/Inventory.h"
#include "../Player/PlayerManager.h"

using namespace std;

void Lobby::Enter()
{
    bIsGameStart = true;
    string inputName;

    Dungeon* dungeon = new Dungeon();
    Inventory* inventory = new Inventory();
    AlchemyWorkShop* alchemyWorkShop = new AlchemyWorkShop();
    
    while (bIsGameStart)
    {
        ShowMenu();
        int selection = InputHelper::GetValidInput<int>("선택: ", 0, 3);
        switch (selection)
        {
        case 1:
            dungeon->Enter();
            if (PlayerManager::GetInstance()->GetPlayer()->IsDead())
            {
                ShowGameOver();
                return;
            }
            break;
        case 2:
            inventory->Enter();
            break;
        case 3:
            alchemyWorkShop->Enter();
            break;
        case 0: Quit();
        }
    }

    delete dungeon;
    delete inventory;
    delete alchemyWorkShop;
}

void Lobby::ShowMenu()
{
    cout <<"=== 메인 메뉴 ===" << endl
    << "1. 던전 입장" << endl
    << "2. 인벤토리 확인" << endl
    << "3. 포션 제작소" << endl
    << "0. 게임 종료" << endl;
}

void Lobby::ShowGameOver()
{
    cout <<"=== 플레이어가 사망하여 게임 종료 ===" << endl;
}

void Lobby::Quit()
{
    bIsGameStart = false;
}

