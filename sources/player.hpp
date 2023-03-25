#ifndef PLAYER_HPP
#define PLAYER_HPP 

    #include <string>
    #include <iostream>
    #include <vector>
    #include "card.hpp"

    using namespace std;
    using namespace ariel;

    class Player{
        private:
        string name;
        int mCardesTaken;
        vector<Card> handCards;
        vector<Card> takenCards;


        public:
        Player(string name);
        int stacksize();
        int cardesTaken();
        void addCard(const Card& card);
        Card getTopCard();
        
    };



#endif // PLAYER_HPP