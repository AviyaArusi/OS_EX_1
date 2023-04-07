#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

 namespace ariel {

    // Game::Game() {}

     Game::Game(Player& player1, Player& player2)  // check about 2 identicle names.
     : p1(player1), p2(player2) 
     {
        if (&p1 == &p2)
        {
            throw invalid_argument("There most be 2 diffrence Players!");
        }
        keep_play = true;
        draw_rounds = 0;
        draw_points_counter = 0;
        reset_pack();
        shuffle_pack();
        deal_pack();
     }

     void Game::playTurn() // add exception
     {
        if(keep_play == false) 
            return;

     // Check that p1 & p2 are 2 difference player.
        // if (p1. p2)
            // throw runtime_error("Can't play with 1 Player only!");
        
        Card p1_card = p1.playTurn();
        Card p2_card = p2.playTurn();
        if ( (p1.stacksize() == 0) && (p1_card.getRank() != p2_card.getRank()) )
        {
            // The last turn.
            keep_play = false;
        }
        else if (  ( (p1.stacksize() == 0) || (p1.stacksize() == 1) ) && (p1_card.getRank() == p2_card.getRank()) ) 
        {
            // Draw in the end of the game --> finish the game.
            draw_rounds++;
            keep_play = false;
            return;
        }
        
        if(p1_card.getRank() == p2_card.getRank())
        {
            draw_rounds++;

            if (draw_points_counter == 0) // if this is single draw.
            {
                draw_points_counter += 3;
            }
            else // If this is multiple draw.
            {
                draw_points_counter += 2;
            }
            // Pull another 2 Cards with the face down and play the next game.
            p1.playTurn();
            p2.playTurn();
            playTurn(); // the next game.
            return;
        }

        updadePoints(p1_card, p2_card);
        pair<Card, Card> cardPair(p1_card, p2_card);
        log.push_back(cardPair);
     }

     void Game::playAll()
     {
        while (keep_play != false)
        {
            playTurn();
        }
     }

     void Game::printWiner() const 
     {

        if( p1.cardesTaken() == p2.cardesTaken() )
        {
            cout << "The game ended in a draw" << endl;
        }
        else if (p1.cardesTaken() > p2.cardesTaken())
        {
            cout << "The winner is :" << p1.getName() << " !" << endl;
        }
        else 
        {
            cout << "The winner is :" << p2.getName() << " !" << endl;
        }
     }

     void Game::printLog() const // add exception
     {
        for (size_t i = 0; i < log.size(); i++)
        {
            pair<Card, Card> cardPair = log[i];
            cout << "Round " << (i+1) << "--> Player_1 card is: (" << dictionary(cardPair.first.getRank()) << ", " << dictionary(cardPair.first.getType()) 
        << ") Player_2 card is: (" << dictionary(cardPair.second.getRank()) << ", " << dictionary(cardPair.second.getType()) << ")" << endl;
        }

     }

     void Game::printStats() const
     {
        cout << p1.getName() << ": \n" <<
                            "win rate --> " << p1.cardesTaken() <<",  cards won --> " << p1.getCardsWon() << " \n" <<
                p2.getName() << ": \n" <<
                            "win rate --> " << p2.cardesTaken() <<",  cards won --> " << p2.getCardsWon() << " \n" << 
                "The number of draw game is --> "  << draw_rounds << endl;

     }
     void Game::printLastTurn() const // add exception! ** only turn that somebody win! **
     {
        size_t last_index = log.size()-1;
        pair<Card, Card> cardPair = log[last_index];
        cout << "Player_1 card is: (" << dictionary(cardPair.first.getRank()) << ", " << dictionary(cardPair.first.getType()) 
        << ") Player_2 card is: (" << dictionary(cardPair.second.getRank()) << ", " << dictionary(cardPair.second.getType()) << ")" << endl;

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
             Card temp = card_pack[size_t(r)];
             card_pack[size_t(r)] = card_pack[size_t(l)];
             card_pack[size_t(l)] = temp;
         }
     }

     void Game::deal_pack()
     {
         for (size_t i = 0; i < 52; ++i)
          {
             if (i % 2 == 0)
             {
                 p1.addCard(card_pack[i]);
             }
             else
             {
                 p2.addCard(card_pack[i]);
             }
         }
     }

      string Game::dictionary(int input) const
    {
        switch(input) 
        {
        case 1:
            return "ACE";
        case 2:
            return "TWO";
        case 3:
            return "THREE";
        case 4:
            return "FOUR";
        case 5:
            return "FIVE";
        case 6:
            return "SIX";
         case 7:
            return "SEVEN";
        case 8:
            return "EIGHT";
        case 9:
            return "NINE";
         case 10:
            return "TEN";
        case 11:
            return "JACK";
        case 12:
            return "QUEEN";
         case 13:
            return "KING";
        case 14:
            return "HEARTS";
        case 15:
            return "DIAMONDS";
         case 16:
            return "CLUBS";
        case 17:
            return "SPADES";
        default:
            // handle invalid input
            throw runtime_error("Invalid input!");
     }
    }

    void Game::updadePoints(Card c_1, Card c_2) // add the ACE case.
    {
        int points = 1;
        if (draw_points_counter != 0)
        {
            points = draw_points_counter;
            draw_points_counter = 0;
        }
        
          if( c_1.getRank() > c_2.getRank() )
        {
            p1.setPoints(points);
        }
        else if (c_1.getRank() < c_2.getRank())
        {
            p2.setPoints(points);
        }
    }

 }
