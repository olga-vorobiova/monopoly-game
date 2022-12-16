//#include "pch.h"
#include "Monopoly.h"
#include <algorithm>

using namespace ::std;

Monopoly::Monopoly(string names[10],int countPlaers)
{
    for (int i = 0; i < countPlaers; i++)
    {
        m_players.push_back(make_shared<Player>(names[i]));
    }
    m_fields.push_back(make_shared<AutoField>("Ford", 0));
    m_fields.push_back(make_shared<FoodField>("MCDonald", 0));
    m_fields.push_back(make_shared<ClotherField>("Lamoda", 0));
    m_fields.push_back(make_shared<TravelField>("Air Baltic", 0));
    m_fields.push_back(make_shared<TravelField>("Nordavia", 0));
    m_fields.push_back(make_shared<PrisonField>("Prison", 0));
    m_fields.push_back(make_shared<FoodField>("Starbucks", 0));
    m_fields.push_back(make_shared<AutoField>("TESLA", 0));
}

const list<shared_ptr<Player>> & Monopoly::GetPlayersList()
{
    return m_players;
}

const list<shared_ptr<Field>> & Monopoly::GetFieldsList()
{
    return m_fields;
}

shared_ptr<Player> Monopoly::GetPlayerInfo(int index)
{
    auto i = m_players.begin();
    advance(i, index - 1);
    return *i;
}

shared_ptr<Field> Monopoly::GetFieldByName(string fieldName)
{
    auto i = find_if(m_fields.begin(), m_fields.end(),[fieldName] (shared_ptr<Field> field) {
        return field->GetName() == fieldName;
    });
    return *i;
}

bool Monopoly::Buy(int index, string fieldName)
{
    auto field = GetFieldByName(fieldName);
    auto player = GetPlayerInfo(index);
  
    return field->Buy(player, index);
}

bool Monopoly::Renta(int index, string fieldName)
{
    auto field = GetFieldByName(fieldName);
    auto player = GetPlayerInfo(index);
    auto owner = GetPlayerInfo(field->GetIndexOfPlayer());

    return field->Rent(player, owner);
}

