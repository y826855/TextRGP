#include "PlayerBase.h"

void PlayerBase::OnHit(int _damage)
{
    auto beforHP = GetHP(); 
    auto damage = max(1, _damage - GetDef());
    AddHP(-damage);

    cout << Data->PlayerName << " 에게 " << damage << " 데미지!" << endl;
    cout << Data->PlayerName << " HP : " << beforHP << " -> " << GetHP();
    if (IsDead()) cout << " (사망)" << endl;
    else cout << endl;
}

bool PlayerBase::IsDead()
{
    return Data->StatArray[HP] <= 0;
}

void PlayerBase::PrintPlayerStatus()
{
    PrintHelper::ShowTwoLine();
    cout << Data->PlayerName << "의 현재 능력치" << endl;
    PrintHelper::ShowTwoLine();
    cout << "HP : " << GetHP() << "\t";
    cout << "MP : " << GetMP() << "\t" << endl;
    cout << "ATK : " << GetAtk() << "\t";
    cout << "DEF : " << GetDef() << "\t" << endl;
    PrintHelper::ShowTwoLine();
}

void PlayerBase::ShowCurrentStat()
{
    PrintHelper::ShowOneLine();
    cout << "닉네임: " << GetName() << " | ";
    cout << GetJobName() << " | ";
    cout << " Lv.1" << endl;
        
    cout << "HP: " << GetHP() << " | ";
    cout << "MP: " << GetMP() << " | ";
    cout << "ATK: " << GetAtk() << " | ";
    cout << "DEF: " << GetDef() << endl;
    PrintHelper::ShowOneLine();
}

string PlayerBase::GetJobName() const
{
    switch (Data->playerJob)
    {
    case EPlayerJob::EArcher: return "궁수";
    case EPlayerJob::EThief: return "도적";
    case EPlayerJob::EMage: return "마법사";
    case EPlayerJob::EWarrior: return "전사";
    default: return "직업없음";
    }
}
