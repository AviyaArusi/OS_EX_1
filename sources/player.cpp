#include "player.hpp"

namespace ariel{
    Player::Player()
    {

    }
    Player::Player(const string)
    {

    }
    int Player::stacksize()
    {
        return 0;
    }
    int Player::cardesTaken()
    {
        return 0;
    }


    void Player::addCard(Card card)
    {
        card_pack.push_back(card);
    }

}