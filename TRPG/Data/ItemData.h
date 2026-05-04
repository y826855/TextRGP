#pragma once
#include <iostream>

using namespace std;

enum EItem
{
    None = 0,
    SlimeJelly = 1,
    Herb = 2,
    Water = 3,
    Berry = 4,
};

struct ItemData
{
private:
    
    string Name = "";
    int Price = 0;
    int Stack = 0; //?
    
public:

    ItemData(string _name, int _price)
    {
        Name = _name;
        Price = _price;
        Stack = 0;
    }

    // 대입 연산자 오버로딩 (Deep Copy 구현)
    ItemData& operator=(const ItemData& other)
    {
        if (this == &other) return *this;
    
        this->Name = other.Name;
        this->Price = other.Price;
        this->Stack = other.Stack;

        return *this;
    }
    
    void PrintInfo() const
    {
        //TODO 출력 메세지 맞추기
        cout << "Name: " << Name << " | Price: " << Price << " | Stack: " << Stack << endl;
    }

};
