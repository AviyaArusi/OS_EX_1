#include "player.hpp"

namespace ariel{
    Player::Player()
    {

    }
    Player::Player(string name) // throw exception " "
    {
        this->name = name;
        points = 0;
        cards_won = 0;
    }

    int Player::stacksize() const
    {
        return card_pack.size();
    }

    int Player::cardesTaken() const
    {
        return points;
    }


    void Player::addCard(Card card)
    {
        card_pack.push_back(card);
    }

    void Player::setPoints(int add)
    {
        cards_won += 1;
        points += add;
    }

    Card Player::playTurn()
    {
        if(card_pack.size() <= 0) // Check what hepennd if 0 < ??
        {
            throw runtime_error("There is nothing to play!");
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

    int Player::getCardsWon() const
    {
        return cards_won;
    }

    //  void Player::shuffle_pack()
    //  {
    //      srand((unsigned) time(NULL));   // Providing a seed value
    //      for (int i = 0; i < 50; ++i) {
    //          int r = rand() % int(card_pack.size());
    //          int l = rand() % int(card_pack.size());
    //          // make swap between the indexes.
    //          Card temp = card_pack[size_t(r)];
    //          card_pack[size_t(r)] = card_pack[size_t(l)];
    //          card_pack[size_t(l)] = temp;
    //      }
    //  }

}