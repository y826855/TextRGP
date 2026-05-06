#include "Dungeon.h"

#include <thread>

#include "../InputHelper.h"
#include "../Inventroy/BattleInventory.h"
#include "../Inventroy/InventoryManager.h"
#include "../Inventroy/ItemManager.h"
#include "../Monster/Dragon.h"
#include "../Monster/Hydra.h"
#include "../Monster/Orc.h"
#include "../Monster/Slime.h"
#include "../Player/PlayerManager.h"

Dungeon::Dungeon()
{
    player = PlayerManager::GetInstance()->GetPlayer();
}

void Dungeon::SelectFloor()
{
    cout << "[ 던전 1층 ]" << endl;
    auto canTryFloor = UnlockedFloor + 1;
    SlimeFloor->ShowFloorInfo(canTryFloor);
    HydraFloor->ShowFloorInfo(canTryFloor);
    OrcFloor->ShowFloorInfo(canTryFloor);

    if (canTryFloor >= 4)
        DragonFloor->ShowFloorInfo(canTryFloor);
    
    int selection = InputHelper::GetValidInput<int>("선택: ", 1, canTryFloor);
    switch (selection)
    {
        case 1: selectedFloor = SlimeFloor; break;
        case 2: selectedFloor = HydraFloor; break;
        case 3: selectedFloor = OrcFloor; break;
        case 4: selectedFloor = DragonFloor; break;
    }
}

void Dungeon::FloorInitialize()
{
    int floorIndex = 0;
    SlimeFloor = new Floor(new Slime, ++floorIndex);
    HydraFloor = new Floor(new Hydra, ++floorIndex);
    OrcFloor = new Floor(new Orc, ++floorIndex);
    DragonFloor = new Floor(new Dragon, ++floorIndex);
}

void Dungeon::Enter()
{
    //층 정보 표기
    FloorInitialize();
    SelectFloor();
    ShowBattleIntro();
    BattleLoop();
    AfterBattle();
}

void Dungeon::BattleLoop()
{
    bIsBattleEnd = false;
    while (true)
    {
        PlayerTurn();
        if (bIsBattleEnd) break;
        
        MonsterTurn();
        if (bIsBattleEnd) break;
    }
    cout << endl;
}

void Dungeon::PlayerTurn()
{
    bool IsPlayerTurn = true;
    auto monster = selectedFloor->GetMonster();
    
    while (IsPlayerTurn)
    {
        cout << "--- 플레이어 턴 ---" << endl;
        cout << "1. 공격" << endl;
        cout << "2. 아이템 사용" << endl;
        int Selection = InputHelper::GetValidInput<int>("선택: ", 1, 2);
        switch (Selection)
        {
        case 1: // 공격
            player->Attack(monster);
            bIsBattleEnd = monster->IsDead();
            IsPlayerTurn = false;
            break;
        case 2: //소모품 사용
            {
                auto inventory = new BattleInventory();
                inventory->Enter();
                delete inventory;
                break;
            }
        }
    }
    
}

void Dungeon::MonsterTurn()
{
    auto monster = selectedFloor->GetMonster();
    cout << "--- " << monster->GetName() << " 턴 ---" << endl;
    monster->Attack(player);
    bIsBattleEnd = player->IsDead(); 
}

void Dungeon::ShowBattleIntro()
{
    auto monster = selectedFloor->GetMonster();
    
    cout << endl;
    
    auto playerName = player->GetName();
    auto playerJob = player->GetJobName();
    cout << "[ 전투 시작! ]" << playerName <<"(" << playerJob
        << ") vs " << monster->GetName() << endl;
}

void Dungeon::AfterBattle()
{
    auto monster = selectedFloor->GetMonster();
    if (monster->IsDead()) Victory();

    delete SlimeFloor; 
    delete HydraFloor; 
    delete OrcFloor; 
    delete DragonFloor;
}

void Dungeon::Victory()
{
    auto monster = selectedFloor->GetMonster();
    auto itemID = monster->GetDropItem().ItemID;
    auto itemName = ItemManager::GetInstance()->GetNameByID(itemID);
    InventoryManager::GetInstance()->AddItem(itemID);
    auto exp = monster->GetExp(); 
    
    cout << "★ 전투 승리!" << endl;
    cout << " -> " << itemName << " 획득!" << endl;
    cout << " -> 인벤토리에 저장되었습니다." << endl;

    player->AddExp(exp);

    auto clearFloor = selectedFloor->GetFloorIndex(); 
    if (UnlockedFloor < clearFloor)
    {
        UnlockedFloor = clearFloor;
        if (UnlockedFloor == 3)
            cout << "★ 보스방 개방!" << endl; 
    }
}
