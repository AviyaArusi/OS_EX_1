#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <vector>
 using namespace std;
 namespace ariel {
//fun banana bla
    Game::Game()
    {

    }
     Game::Game(Player& p1, Player& p2)
     {

     }

     void Game::playTurn()
     {

     }

     void Game::playAll()
     {

     }

     void Game::printWiner()
     {

     }

     void Game::printLog()
     {

     }

     void Game::printStats()
     {

     }
     void Game::printLastTurn()
     {

     }

     void Game::reset_pack()
     {
         for (int rank = 1; rank < 14; ++rank)
         {
             for (int type = 14; type < 18 ; ++type)
             {
                 card_pack.push_back(Card(rank, type));


             }
         }
     }

     void Game::shuffle_pack()
     {
         srand((unsigned) time(NULL));   // Providing a seed value
         for (int i = 0; i < 100; ++i) {
             int r = rand() % 52;
             int l = rand() % 52;
             // make swap between the indexes.
             Card temp = card_pack[r];
             card_pack[r] = card_pack[l];
             card_pack[l] = temp;
         }
     }

     void Game::deal_pack()
     {
         for (int i = 0; i < 52; ++i) {
             if (i % 2 == 0)
             {
                 p1.addCard(deck[i]);
             }
             else
             {
                 p2.addCard(deck[i]);
             }
         }
     }


 }
