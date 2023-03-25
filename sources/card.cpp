#include "card.hpp"
using namespace ariel;

Card::Card(int value, Suit suit){
    if (value < 2 || value > 14)
    {
        throw "Invalid card value";
    }
   
    
   
};

Card :: Card(){
    
};

int Card::getValue(){
    return 0;
};

Card::Suit Card::getSuit(){
    return this->suit;
};

std::string Card :: getSuitString(Suit suit) {
    switch(suit) {
        case HEARTS:
            return "Hearts";
        case DIAMONDS:
            return "Diamonds";
        case SPADES:
            return "Spades";
        case CLUBS:
            return "Clubs";
        default:
            return "";
    }
}
void Card :: printCard(){
    std::string str = " ";
    switch (this->value){
        case 14:
            str = "Ace";
            break;
        case 11:
            str = "Jack";
            break;
        case 12:
            str = "Queen";
            break;
        case 13:
            str = "King";
            break;
        default:
            str = std::to_string(this->value);
            break;
    }
    std::cout << str << " of " << getSuitString(this->suit) << std::endl;
}
