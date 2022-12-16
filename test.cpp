
#include "Monopoly.h"
using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("GetPlayersListReturnCorrectList") {
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players,3);

    auto list = monopoly.GetPlayersList();
    int i = 0;
    for (auto player : list) {
        CHECK(player->GetName() == players[i++]);
        CHECK(player->GetAmountOfMoney() == 6000);
    }
    CHECK(i);
}

TEST_CASE("GetFieldsListReturnCorrectList") {
    shared_ptr<Field> expectedCompanies[]{
        make_shared<AutoField>("Ford",0),
        make_shared<FoodField>("MCDonald",0),
        make_shared<ClotherField>("Lamoda",0),
        make_shared<TravelField>("Air Baltic",0),
        make_shared<TravelField>("Nordavia",0),
        make_shared<PrisonField>("Prison",0),
        make_shared<FoodField>("Starbucks",0),
        make_shared<AutoField>("TESLA",0)
    };
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto actualCompanies = monopoly.GetFieldsList();
    int i = 0;
    for (auto company : actualCompanies)
    {
        CHECK(company == expectedCompanies[i++]);
    }
    CHECK(i);
}

TEST_CASE("PlayerBuyNoOwnedCompanies")
{
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto company = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, company->GetName());

    auto player = monopoly.GetPlayerInfo(1);
    CHECK(player->GetAmountOfMoney() == 5500);
    CHECK(company->GetIndexOfPlayer() != 0);
}

TEST_CASE("PlayerBuyOwnedCompanies")
{
    string players[]{ "Peter","Ekaterina","Alexander" };

    Monopoly monopoly(players, 3);
    auto company = monopoly.GetFieldByName("Lamoda");
    monopoly.Buy(3, company->GetName());
    CHECK(monopoly.Buy(1, company->GetName()) == false);

    auto player1 = monopoly.GetPlayerInfo(1);
    CHECK(player1->GetAmountOfMoney() == 6000);
    auto player2 = monopoly.GetPlayerInfo(3);
    CHECK(player2->GetAmountOfMoney() == 5900);
    CHECK(company->GetIndexOfPlayer() == 3);
}

TEST_CASE("RentaOfAutoShouldBeCorrectTransferMoney")
{
    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);
    auto company = monopoly.GetFieldByName("Ford");
    monopoly.Buy(1, company->GetName());

    monopoly.Renta(2, company->GetName());
    auto player1 = monopoly.GetPlayerInfo(1);
    CHECK(player1->GetAmountOfMoney() == 5750);

    auto player2 = monopoly.GetPlayerInfo(2);
    CHECK(player2->GetAmountOfMoney() == 5750);
}

TEST_CASE("RentaOfFoodShouldBeCorrectTransferMoney")
{
    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);
    auto company = monopoly.GetFieldByName("MCDonald");
    monopoly.Buy(3, company->GetName());

    CHECK(monopoly.Renta(2, company->GetName()) == true);
    auto player1 = monopoly.GetPlayerInfo(3);
    CHECK(player1->GetAmountOfMoney() == 5750);

    auto player2 = monopoly.GetPlayerInfo(2);
    CHECK(player2->GetAmountOfMoney() == 6000);
}

TEST_CASE("RentaOfPrisonShouldBeCorrectTransferMoney")
{
    string players[]{ "Peter","Ekaterina","Alexander" };
    Monopoly monopoly(players, 3);
    auto company = monopoly.GetFieldByName("Prison");
    CHECK(monopoly.Buy(1, company->GetName()) == false);

    monopoly.Renta(2, company->GetName());
    auto player1 = monopoly.GetPlayerInfo(2);
    CHECK(player1->GetAmountOfMoney() == 5000);
}

bool operator==(shared_ptr<Field>& field1, shared_ptr<Field>& field2)
{
    return typeid(*field1).name() == typeid(*field2).name() && field1->GetName() == field2->GetName() && field1->GetIndexOfPlayer() == field2->GetIndexOfPlayer();
}

