#pragma once
#include <iostream>

using namespace std;

class PrintHelper
{
public:
    static void ShowIntro()
    {
        ShowTwoLine();
        cout << "[ 던전 탈출 텍스트 RPG ]" << '\n';
        ShowTwoLine();
    }

    static void ShowTwoLine()
    {
        cout << "===========================================" << '\n';
    }

    static void ShowOneLine()
    {
        cout << "------------------------------------" << '\n';
    }
};
