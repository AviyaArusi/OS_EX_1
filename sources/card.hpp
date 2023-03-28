#ifndef EX_1_CARD_H
#define EX_1_CARD_H

#include <iostream>

using namespace std;

namespace ariel{

    class Card
    {
        enum Rank { ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
        enum Type { HEARTS=14, DIAMONDS, CLUBS, SPADES };
    private:
        Rank rank;
        Type type;
    public:
        Card();
        Card(Rank, Type);
        Rank getRank();
        Type getType();
    };
}




#endif //EX_1_CARD_H
