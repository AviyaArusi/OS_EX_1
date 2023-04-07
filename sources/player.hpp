#ifndef EX_1_PLAYER_H
#define EX_1_PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"


using namespace std;
namespace ariel{

    class Player {
    private:
        string name;
        int points;
        int cards_won;
        vector <Card> card_pack;

    public:
        Player();
        Player(string);
        int stacksize() const;
        int cardesTaken()const;

        //*****
        void addCard(Card);
        void setPoints(int);
        Card playTurn();
        string getName() const;
        int getCardsWon() const;
        // void shuffle_pack();
    };
}
#endif //EX_1_PLAYER_H
