#include "doctest.h"
#include <sstream>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;


TEST_CASE("Test Card") {
    Card c1(14, Card::HEARTS);
    CHECK(c1.getValue() == 14);
    CHECK(c1.getSuit() == Card::HEARTS);
    CHECK(c1.getSuitString(Card::HEARTS) == "Hearts");
    CHECK(c1.getSuitString(Card::DIAMONDS) == "Diamonds");
    CHECK(c1.getSuitString(Card::SPADES) == "Spades");
    //CHECK(c1.printCard() == "Ace of Hearts");

    //CHECK_THROWS(Card c2(1, Card::HEARTS) == "Invalid card value");
}
TEST_CASE("Test Player") {
    Player p1("p1");
    CHECK(p1.stacksize() == 0);
    CHECK(p1.cardesTaken() == 0);
    p1.addCard(Card(14, Card::HEARTS));
    CHECK(p1.stacksize() == 1);
    CHECK(p1.cardesTaken() == 1);
    CHECK(p1.getTopCard().getValue() == 14);
    CHECK(p1.getTopCard().getSuit() == Card::HEARTS);
    CHECK(p1.getTopCard().getSuitString(Card::HEARTS) == "Hearts");
    CHECK(p1.getTopCard().getSuitString(Card::DIAMONDS) == "Diamonds");
    CHECK(p1.getTopCard().getSuitString(Card::SPADES) == "Spades");
    
   
}
TEST_CASE("Test While playing") {
    Player p1("p1");
    Player p2("p2");
    Game g(p1, p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);

    g.playTurn();
    CHECK(p1.stacksize() == 25);
    CHECK(p2.stacksize() == 27);
    CHECK(p1.cardesTaken() == 1);
    //or
    CHECK(p1.stacksize() == 27);
    CHECK(p2.stacksize() == 25);
    CHECK(p2.cardesTaken() == 1);
    //or drow case: wines after 1 round
    CHECK(p1.stacksize() == 23);
    CHECK(p2.stacksize() == 29);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 3);//the question is if player lose card? dose cardesTaken() count the card that player lose?
    //-------- and we can and more of the same for round 2,3,4.. ..


    g.playAll();
    CHECK_THROWS(g.playTurn());

    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 52);
    CHECK(p2.cardesTaken() == 26);//maybe more depends on what you will dicide.
    //or
    CHECK(p1.stacksize() == 52);
    CHECK(p2.stacksize() == 0);
    CHECK(p1.cardesTaken() == 26);//maybe more depends on what you will dicide.

    CHECK_THROWS(g.playAll());

    SUBCASE("add cards"){
        p1.addCard(Card(14, Card::HEARTS));
        CHECK(p1.stacksize() == 1);
        CHECK(p1.cardesTaken() == 1);
        CHECK(p1.getTopCard().getValue() == 14);
        CHECK(p1.getTopCard().getSuit() == Card::HEARTS);
        CHECK(p1.getTopCard().getSuitString(Card::HEARTS) == "Hearts");
        CHECK(p1.getTopCard().getSuitString(Card::DIAMONDS) == "Diamonds");
        CHECK(p1.getTopCard().getSuitString(Card::SPADES) == "Spades");
    }
    
}

