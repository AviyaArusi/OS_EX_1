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
        Player& p1;
        Player& p2;                 // The 2 player of the game.
        vector<pair<Card, Card>> log; // All the turn one after another.
        vector<Card> card_pack;      // Hold the full pack in the start of the Game.
        bool keep_play;
        bool game_status;
        int draw_rounds;
    public:
        // Constructor's
        Game();
        Game(Player&, Player&);

        void playTurn();
        void printLastTurn() const;
        void playAll();
        void printWiner();
        void printLog() const;
        void printStats() const;

        //***
        void reset_pack();
        void shuffle_pack();
        void deal_pack();
        string dictionary(int);
        void updadePoints(Card, Card, int);
        void drawEnd();

    };

}

#endif //EX_1_GAME_H
