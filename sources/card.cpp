#include "card.hpp"

namespace ariel{

    Card::Card()
    {

    }
    Card::Card(int rank, int type )
    {
        this->rank = rank;
        this->type = type;
    }

    int Card::getRank()
    {
        return rank;
    }
    int Card::getType()
    {
        return type;
    }

    string Card::dictionary(int input)
    {
        switch(input) {
        case 1:
            return "ACE";
        case 2:
            return "TWO";
        case 3:
            return "THREE";
        case 4:
            return "FOUR";
        case 5:
            return "FIVE";
        case 6:
            return "SIX";
         case 7:
            return "SEVEN";
        case 8:
            return "EIGHT";
        case 9:
            return "NINE";
         case 10:
            return "TEN";
        case 11:
            return "JACK";
        case 12:
            return "QUEEN";
         case 13:
            return "KING";
        case 14:
            return "HEARTS";
        case 15:
            return "DIAMONDS";
         case 16:
            return "CLUBS";
        case 17:
            return "SPADES";
        default:
            // handle invalid input
     }
    }


}