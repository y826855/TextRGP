#pragma once
#include "ItemData.h"

struct MonsterData
{
public:
    int HP;
    int Atk;
    int Def;
    
    ItemData DropItem; // string 으로 처리하지 않음
};
