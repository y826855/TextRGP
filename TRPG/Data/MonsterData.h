#pragma once
#include "ItemData.h"

struct MonsterData
{
public:
    string Name;
    
    int HP;
    int Atk;
    int Def;
    int Exp;
    
    RequireItem DropItem; // string 으로 처리하지 않음

    MonsterData(const string& _name, int _hp, int _atk, int _def, int _exp, const RequireItem _dropItem)
        : Name(_name), HP(_hp), Atk(_atk), Def(_def), Exp(_exp),DropItem(_dropItem)
    {
        
    }
};
