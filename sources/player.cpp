#include "player.hpp"

namespace ariel{
    Player::Player()
    {

    }
    Player::Player(string name) // throw exception " "
    {
        this->name = name;
        points = 0;
    }

    int Player::stacksize() const
    {
        return card_pack.size();
    }

    int Player::cardesTaken() const
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
        if(card_pack.size() <= 0) // Check what hepennd if 0 < ??
        {
            // throw exception("There is nothing to play!");
        }
        size_t last_index = card_pack.size()-1;
        Card ans = card_pack[last_index];
        card_pack.pop_back();
        return ans;
    }

    string Player::getName() const
    {
        return name;
    }

     void Player::shuffle_pack()
     {
         srand((unsigned) time(NULL));   // Providing a seed value
         for (int i = 0; i < 50; ++i) {
             int r = rand() % int(card_pack.size());
             int l = rand() % int(card_pack.size());
             // make swap between the indexes.
             Card temp = card_pack[size_t(r)];
             card_pack[size_t(r)] = card_pack[size_t(l)];
             card_pack[size_t(l)] = temp;
         }
     }

}