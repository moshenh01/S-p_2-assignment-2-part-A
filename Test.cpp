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
    CHECK(p1.cardesTaken() == 0);
    Card c1 = p1.getTopCard();
    CHECK(c1.getValue() == 14);
    CHECK(c1.getSuit() == Card::HEARTS);
    CHECK(p1.stacksize() == 0);
    CHECK(c1.getSuitString(c1.getSuit()) == "Hearts");
   
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
    CHECK(p2.stacksize() == 25);
    CHECK(((p1.cardesTaken() == 1) || (p2.cardesTaken() == 1)));
    //or
    
    g.playAll();
    CHECK_THROWS(g.playTurn());

    CHECK((p1.stacksize() == 0 || p2.stacksize() == 0));
    

    CHECK_THROWS(g.playAll());

    //i did test only for the commned you wrote in demo

    
}

