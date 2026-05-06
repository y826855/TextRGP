#pragma once

#include <iostream>

#include "InputHelper.h"
#include "PrintHelper.h"
#include "Inventroy/InventoryManager.h"
#include "Player/PlayerManager.h"

#include "Player/Archer.h"
#include "Player/Mage.h"
#include "Player/PlayerBase.h"
#include "Player/Thief.h"
#include "Player/Warrior.h"

#include "Lobby/Lobby.h"

using namespace std;

void Intro();
void ControlState();
void IntroDebug();

int main(int argc, char* argv[])
{
    //Intro();
    IntroDebug();
    
    PlayerManager::GetInstance()->GetPlayer()->ShowJobStat();
    PlayerManager::GetInstance()->GetPlayer()->ShowCurrentStat();
    
    ControlState();

    Lobby* lobby = new Lobby();
    lobby->Enter();
    delete lobby;
    
    return 0;
}

//입력 하기 귀찮아서 테스트용
void IntroDebug()
{
    PrintHelper::ShowIntro();
    string name = "테스트";
    int inputStat[4] = { 50, 50 , 40 ,40};
    int jobSelection = 3;

    PlayerBase* player = nullptr;
    
    switch (jobSelection)
    {
    case 1: player = new Warrior(name, inputStat); break;
    case 2: player = new Mage(name, inputStat); break;
    case 3: player = new Thief(name, inputStat); break;
    case 4: player = new Archer(name, inputStat); break;
    }
    
    PlayerManager::GetInstance()->SetPlayer(player);
}

void Intro()
{
    PrintHelper::ShowIntro();
    string name = InputHelper::GetValidName("용사의 이름을 입력해주세요: ", 2, 10);
    int inputStat[4];
    // HP, MP 한 번에 입력 (50~999)
    auto stats = InputHelper::GetMultiValidInput<int>("HP와 MP를 입력해주세요: ", 2, 50, 999);
    inputStat[EStat::HP] = stats[0];
    inputStat[EStat::MP] = stats[1];

    // ATK, DEF 한 번에 입력 (10~999)
    auto combat = InputHelper::GetMultiValidInput<int>("공격력과 방어력을 입력해주세요: ", 2, 10, 999);
    inputStat[EStat::ATK] = combat[0];
    inputStat[EStat::DEF] = combat[1];

    // 직업 선택
    cout << "\n< 전직 시스템 >\n" << name << "님, 직업을 선택해주세요!\n";
    cout << "1. 전사   2. 마법사   3. 도적   4. 궁수\n";
    int jobSelection = InputHelper::GetValidInput<int>("선택: ", 1, 4);

    PlayerBase* player = nullptr;
    
    switch (jobSelection)
    {
    case 1: player = new Warrior(name, inputStat); break;
    case 2: player = new Mage(name, inputStat); break;
    case 3: player = new Thief(name, inputStat); break;
    case 4: player = new Archer(name, inputStat); break;
    }
    
    PlayerManager::GetInstance()->SetPlayer(player);
}

//Enterable 상속받는 클래스로 분리해서 사용하는게 좋음 
void ControlState()
{
    auto InventoryMgr = InventoryManager::GetInstance();
    auto Player = PlayerManager::GetInstance()->GetPlayer();
    InventoryMgr->AddPotion(EPotion::EHPPotion, 5);
    InventoryMgr->AddPotion(EPotion::EMPPotion, 5);

    cout << "HP 포션 5개, MP 포션 5개가 기본 지급되었습니다." <<endl;
    PrintHelper::ShowTwoLine();
    cout << "< 캐릭터 강화 >" << endl;
    cout << "1. HP UP" << "\t"
    <<  "2. MP UP" << "\t"
    <<  "3. 공격력 2배" << endl
    <<  "4. 방어력 2배"  << "\t"
    <<  "5. 현재 능력치" << "\t"
    <<  "0. 게임 시작" << endl;
    
    bool bReadyToStart = false;
    while (!bReadyToStart)
    {
        int selection = InputHelper::GetValidInput<int>("선택: ", 0, 5);
        switch (selection)
        {
        case 0:
            cout << "게임을 시작합니다!" << endl;
            bReadyToStart = true;
            break;
        case 1:
            InventoryManager::GetInstance()->UsePotion(EPotion::EHPPotion);
            break;
        case 2:
            InventoryManager::GetInstance()->UsePotion(EPotion::EMPPotion);
            break;
        case 3:
        {
            int prevATK = Player->GetAtk(); 
            int currATK = Player->GetAtk() * 2;
            Player->SetAtk(currATK);
            cout << "공격력 2배! " << prevATK << " -> " << currATK << endl;
            break;
        }
        case 4:
        {
            int prevDEF = Player->GetDef(); 
            int currDEF = Player->GetDef() * 2;
            Player->SetDef(currDEF);
            cout << "방어력 2배! " << prevDEF << " -> " << currDEF << endl;
            break;
        }
        case 5:
            Player->ShowCurrentStat();
            break;
        }
    }
}
