#include "Dungeon.h"

#include <thread>

#include "../Inventroy/InventoryManager.h"
#include "../Inventroy/ItemManager.h"
#include "../Monster/Hydra.h"
#include "../Player/PlayerManager.h"

Dungeon::Dungeon()
{
    player = PlayerManager::GetInstance()->GetPlayer();
}

void Dungeon::Initalize()
{
    int randomValue = rand() % 2;
    
    if (randomValue == 0)
        monster = new Slime();
    else 
        monster = new Hydra();
}

void Dungeon::Enter()
{
    Initalize();
    ShowBattleIntro();

    while (true)
    {
        cout << "--- 플레이어 턴 ---" << endl;
        player->Attack(monster);
        if (monster->IsDead()) break;
        
        this_thread::sleep_for(chrono::milliseconds(200));

        cout << "--- " << monster->GetName() << " 턴 ---" << endl;
        monster->Attack(player);
        if (player->IsDead()) break;
    }
    cout << endl;
    AfterBattle();
}

void Dungeon::ShowBattleIntro()
{
    cout << endl;
    
    auto playerName = player->GetName();
    auto playerJob = player->GetJobName();
    cout << "[ 전투 시작! ]" << playerName <<"(" << playerJob
        << ") vs " << monster->GetName() << endl;
}

void Dungeon::AfterBattle()
{
    if (monster->IsDead()) Victory();
    delete monster;
}

void Dungeon::Victory() const
{
    auto itemID = monster->GetDropItem().ItemID;
    auto itemName = ItemManager::GetInstance()->GetNameByID(itemID);
    InventoryManager::GetInstance()->AddItem(itemID);
    
    cout << "★ 전투 승리!" << endl;
    cout << " -> " << itemName << " 획득!" << endl;
    cout << " -> 인벤토리에 저장되었습니다." << endl;

    InventoryManager::GetInstance()->ShowInventory();
}
