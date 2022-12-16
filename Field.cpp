
#include "Field.hpp"
#include <iostream>
Field::Field(string name, int index): m_name(name), m_indexOfPlayer(index), m_price(0), m_rent(0)
{    
}

void Field::SetName(const string name)
{
    m_name = name;
}

string Field::GetName() const
{
    return m_name;
}

void Field::SetIndexOfPlayer(const int index)
{
    m_indexOfPlayer = index;
}

int Field::GetIndexOfPlayer() const
{
    return m_indexOfPlayer;
}

int Field::GetPrice() const
{
    return m_price;
}

bool Field::Buy(shared_ptr<Player> player, int index)
{
    if(!m_indexOfPlayer)
    {
        int amountOfMoney = player->GetAmountOfMoney() - m_price;
        player->SetAmountOfMoney(amountOfMoney);
        m_indexOfPlayer = index;
        return true;
    }
    return false;
}

RentField::RentField(string name, int index): Field(name, index)
{
}

bool RentField::Rent(shared_ptr<Player> player, shared_ptr<Player> owner)
{
    if(m_indexOfPlayer)
    {
        player->SetAmountOfMoney(player->GetAmountOfMoney() - m_rent);
        owner->SetAmountOfMoney(owner->GetAmountOfMoney() + m_rent);
        return true;
    }
    return false;
}

AutoField::AutoField(string name, int index): RentField(name, index)
{
    m_price = 500;
    m_rent = 250;
}

TravelField::TravelField(string name, int index): RentField(name, index)
{
    m_price = 700;
    m_rent = 250;
}

ClotherField::ClotherField(string name, int index): RentField(name, index)
{
    m_price = 100;
    m_rent = 250;
}

FoodField::FoodField(string name, int index): Field(name, index)
{
    m_price = 250;
}

bool FoodField::Rent(shared_ptr<Player> player, shared_ptr<Player> owner)
{
    return m_indexOfPlayer;
}

PunishmentField::PunishmentField(string name, int index): Field(name, index)
{
}

bool PunishmentField::Buy(shared_ptr<Player> player, int index)
{cout<<"BBBBB"<<endl;
    return false;
}

bool PunishmentField::Rent(shared_ptr<Player> player, shared_ptr<Player> owner)
{
    player->SetAmountOfMoney(player->GetAmountOfMoney() - m_rent);
    return true;
}

PrisonField::PrisonField(string name, int index): PunishmentField(name, index)
{
    m_rent = 1000;
}

BankField::BankField(string name, int index): PunishmentField(name, index)
{
    m_rent = 700;
}
