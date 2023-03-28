#include "card.hpp"

namespace ariel{

    Card::Card()
    {

    }
    Card::Card(Rank rank, Type type )
    {
        this->rank = rank;
        this->type = type;
    }

    Rank Card::getRank()
    {
        return rank;
    }
    Type Card::getType()
    {
        return type;
    }


}