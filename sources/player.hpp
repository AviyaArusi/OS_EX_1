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
        vector <Card> card_pack;

    public:
        Player();
        Player(string);
        int stacksize();
        int cardesTaken();

        //*****
        void addCard(Card);
        void setPoints(int);
        Card playTurn();
        string getName();
        void shuffle_pack();
    };
}
#endif //EX_1_PLAYER_H
