#pragma once

#include <string>
#include "Player.hpp"
using namespace std;

class Field
{
protected:
    string m_name;
    int m_indexOfPlayer;
    int m_price;
    int m_rent;
    
public:
    Field(string, int);
    
    void SetName(const string);
    string GetName() const;

    void SetIndexOfPlayer(const int);
    int GetIndexOfPlayer() const;

    int GetPrice() const;
    
    virtual bool Buy(shared_ptr<Player>, int);
    virtual bool Rent(shared_ptr<Player>, shared_ptr<Player>) = 0;
};



class RentField: public Field
{
public:
    RentField(string, int);
    bool Rent(shared_ptr<Player>, shared_ptr<Player>);
};

class AutoField: public RentField
{
public:
    AutoField(string, int);
};

class TravelField: public RentField
{
public:
    TravelField(string, int);
};

class ClotherField: public RentField
{
public:
    ClotherField(string, int);
};



class FoodField: public Field
{
public:
    FoodField(string, int);
    bool Rent(shared_ptr<Player>, shared_ptr<Player>);
};



class PunishmentField: public Field
{
public:
    PunishmentField(string, int);
    bool Rent(shared_ptr<Player>, shared_ptr<Player>);
    bool Buy(shared_ptr<Player>, int);
};

class PrisonField: public PunishmentField
{
public:
    PrisonField(string, int);
};

class BankField: public PunishmentField
{
public:
    BankField(string, int);
};
