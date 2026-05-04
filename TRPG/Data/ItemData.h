#pragma once
#include <iostream>

using namespace std;

enum class EItem
{
    None = 0,
    SlimeJelly = 1,
    Herb = 2,
    Water = 3,
    Berry = 4,
};

struct RequireItem
{
    EItem ItemID;
    int Amount;

    RequireItem(EItem _id, int _amount);
    void ShowInfo();
};


struct ItemData
{
    
private:
    
    string Name = "";
    int Price = 0;
    
public:

    ItemData(string _name, int _price);

    // 대입 연산자 오버로딩 (Deep Copy 구현)
    ItemData& operator=(const ItemData& other);

    string GetName() { return Name; }
    
    void PrintInfo() const;
};
