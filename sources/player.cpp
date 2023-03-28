#include "player.hpp"

namespace ariel{
    Player::Player()
    {

    }
    Player::Player(const string name)
    {
        this->name = name;
        points = 0;
    }
    int Player::stacksize()
    {
        return card_pack.size();
    }
    int Player::cardesTaken()
    {
        return points/2;
    }


    void Player::addCard(Card card)
    {
        card_pack.push_back(card);
    }
    void Player::setPoints(int add)
    {
        points += add*2;
    }

    Card Player::playTurn()
    {
        if(card_pack.size() > 0) // Check what hepennd if 0 < ??
        {
            // return card_pack[0]; ******************************************
        }
        size_t last_index = card_pack.size()-1;
        Card ans = card_pack[last_index];
        card_pack.pop_back();
        return ans;
    }

    string Player::getName()
    {
        return name;
    }

}