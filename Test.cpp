#include "doctest.h"
#include <sstream>
#include <stdexcept>
#include <exception>
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
    

  
}
TEST_CASE("Test Player") {
    Player p3("p3");
    CHECK(p3.stacksize() == 0);
    CHECK(p3.cardesTaken() == 0);
    p3.addCard(Card(14, Card::HEARTS));
    CHECK(p3.stacksize() == 1);
    CHECK(p3.cardesTaken() == 0);
    Card c1 = p3.getTopCard();
    CHECK(c1.getValue() == 14);
    CHECK(c1.getSuit() == Card::HEARTS);
    CHECK(p3.stacksize() == 0);
    CHECK(c1.getSuitString(c1.getSuit()) == "Hearts");
   
}

TEST_CASE("Test While playing") {
    Player p1("alice");
    Player p2("bob");
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
    //when the game is over there is one of three options...
    CHECK((p1.getIsWinner() || p2.getIsWinner()|| g.getIsDraw()));
    CHECK_THROWS(g.playTurn());

    CHECK((p1.stacksize() == 0 && p2.stacksize() == 0));
    

    CHECK_THROWS(g.playAll());

    //i did test only for the commned you wrote in demo

    
}

