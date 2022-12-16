
#include "Player.hpp"

Player::Player(string name, int amount) : m_name(name), m_amountOfMoney(amount)
{
}

void Player::SetName(const string name)
{
    m_name = name;
}

string Player::GetName() const
{
    return m_name;
}

void Player::SetAmountOfMoney(const int amount)
{
    m_amountOfMoney = amount;
}

int Player::GetAmountOfMoney() const
{
    return m_amountOfMoney;
}
