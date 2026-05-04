#pragma once

#include <iostream>

#include "InputHelper.h"
#include "PrintHelper.h"
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

    //TODO 포션 사용 & 스텟 업

    Lobby* lobby = new Lobby();
    lobby->Enter();
    delete lobby;
    
    return 0;
}

void IntroDebug()
{
    PrintHelper::ShowIntro();
    string name = "테스트";
    int inputStat[4] = { 50, 50 , 20 ,20};
    int jobSelection = 1;

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
void ControlState()
{

//* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다.
// ============================================
// < 캐릭터 강화 >
// 1. HP UP    2. MP UP    3. 공격력 2배
// 4. 방어력 2배  5. 현재 능력치  0. 게임 시작
// ============================================
// 번호를 선택해주세요: 1
// * HP가 20 증가했습니다. (HP 포션 차감: 남은 포션 4개)
// 번호를 선택해주세요: 0
// 게임을 시작합니다!
}
