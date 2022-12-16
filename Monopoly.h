#pragma once

#include <list>
#include <tuple>
#include <string>
#include <memory>
#include "Player.hpp"
#include "Field.hpp"

using namespace std;

class Monopoly
{
    list<shared_ptr<Player>> m_players;
    list<shared_ptr<Field>> m_fields;
    
public:

    Monopoly(std::string names[10],int);
    
    const list<shared_ptr<Player>> & GetPlayersList();
    const list<shared_ptr<Field>> & GetFieldsList();
    
    shared_ptr<Field> GetFieldByName(string);
    shared_ptr<Player> GetPlayerInfo(int);
    
    bool Buy(int, string);
    bool Renta(int, string);
    
    
};


