#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <fstream>

namespace ariel{
    class Card{
        public:
        enum Suit{
            HEARTS,
            DIAMONDS,
            SPADES,
            CLUBS
        };
        private:
            int value;
            Suit suit;

        public:
            Card(int value, Suit suit);
            Card();
            int getValue();
            Suit getSuit();
            void setValue(int value);
            std::string getSuitString(Suit suit);
            void printCard();
    };
}
#endif // CARD_HPP