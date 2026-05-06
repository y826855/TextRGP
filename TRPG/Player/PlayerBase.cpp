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


void PlayerBase::OnHit(int _damage, int _count)
{
    auto beforHP = GetHP(); 
    auto damage = max(1, _damage - GetDef());

    for (int i = 0; i < _count; i++)
        AddHP(-damage);

    cout << Data->PlayerName << " 에게 " << damage << " 데미지!" << "(x" << _count << ")" << endl;
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
    cout << " Lv." << Data->Level << endl;
        
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

void PlayerBase::AddExp(int _exp) const
{
    auto beforeExp = Data->Exp; 
    Data->Exp += _exp;
    
    auto levelUp = Data->Exp / GetMaxExp();
    Data->Exp = Data->Exp % GetMaxExp();
    
    cout << " -> 경험치 +" << _exp <<" 획득!" << "(현재 경험치: " << beforeExp + _exp << "/" << GetMaxExp() << ")" << endl; 

    if (levelUp > 0)
        LevelUp(levelUp);
}

void PlayerBase::LevelUp(int _levelUpCount) const
{
    auto hpAmount = 10 * _levelUpCount;
    auto mpAmount = 5 * _levelUpCount;
    auto atkAmount = 5 * _levelUpCount;
    
    AddHP(hpAmount);
    AddMP(mpAmount);
    AddAtk(atkAmount);
    
    cout << "  ... 레벨업 조건 충족" << endl; 
    cout << " -> 레벨 업! Lv." << Data->Level << " -> Lv." << Data->Level + _levelUpCount << endl; 
    cout << " -> HP +" << hpAmount
    << ", MP +" << mpAmount
    << ", 공격력 +"<< atkAmount
    << " 증가!" << endl;

    Data->Level += _levelUpCount;
}

