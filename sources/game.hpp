#ifndef EX_1_GAME_H
#define EX_1_GAME_H

#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <cstdlib> // For the random number
#include "player.hpp"
#include "card.hpp"

using namespace std;
namespace ariel{

    class Game{
    private:
        Player p1, p2;                 // The 2 player of the game.
        vector<pair<Card, Card>> log; // All the turn one after another.
        vector<Card> card_pack;      // Hold the full pack in the start of the Game.
    public:
        // Constructor's
        Game();
        Game(Player&, Player&);

        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

        //***
        void reset_pack();
        void shuffle_pack();
        void deal_pack();

    };

}

#endif //EX_1_GAME_H
