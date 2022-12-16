#pragma once

#include <string>
using namespace std;

class Player
{
    string m_name;
    int m_amountOfMoney;
    static const int defaultAmountOfMoney = 6000;
public:

    Player(string name, int amount = defaultAmountOfMoney);
   
    void SetName(const string name);
    string GetName() const;
    
    void SetAmountOfMoney(const int amount);
    int GetAmountOfMoney() const;
    
};



