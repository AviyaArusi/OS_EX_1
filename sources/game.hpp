#ifndef EX_1_GAME_H
#define EX_1_GAME_H

#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <cstdlib> // For the random number.
#include <stdexcept> // For the exception.
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
        int draw_rounds;
        int draw_points_counter;
    public:
        // Constructor's
        Game();
        Game(Player&, Player&);

        void playTurn();
        void printLastTurn() const;
        void playAll();
        void printWiner() const;
        void printLog() const;
        void printStats() const;

        //***
        void reset_pack();
        void shuffle_pack();
        void deal_pack();
        string dictionary(int) const;
        void updadePoints(Card, Card);
    };

}

#endif //EX_1_GAME_H
