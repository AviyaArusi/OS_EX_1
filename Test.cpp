#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
//**
#include <cassert>
#include "doctest.h"
// #include 
//**
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;



TEST_CASE("Creat Player")
{
    Player player("Aviya Arusi");
    // Test_: creat Player and check it is not null() --> if we can use some function in player so it is not null.
    CHECK_NOTHROW(player.stacksize());
    
    // Test_: can't creat Player with " " empty name.
    CHECK_THROWS( Player("") );

    // Test_: can't creat null Player.
    CHECK_THROWS( Player(nullptr) );

    // Test_: check that Player.stackSize() == 0 before entry to any Game.
    CHECK(player.stacksize() == 0);

    // Test_: check that Player.cardesTaken() == 0 before any playTurn().
    CHECK(player.cardesTaken() == 0);
}


TEST_CASE("Creat Game 1")
{
    Player alice("Alice");
    Player bob("Bob");
    Game game(alice, bob);
    
    // Test_: creat Game end check it is not null --> if we can use some function from game it is not null.
    // here we expect from the "game" to print the start stats. 
    CHECK_NOTHROW(game.printStats());

    // Test_: can't printLog() before played any turn.
    CHECK_THROWS(game.printLog());

    // Test_: can't printWinner() before the end of the game.
    CHECK_THROWS(game.printWiner());

    // Tset_:  check for equal number of cards for every player after the start of the game 
    //                                   Player_1.stackSize() == Player_1.stackSize() == 26.
    CHECK( ( (alice.stacksize() == 26) && ( bob.stacksize() == 26) ) );
}

TEST_CASE("Creat Game 2")
{
    Player alice("Alice");
    Player bob("Bob");
    Player aviya("Aviya");
    Game game(alice, bob);

    // Test_: cant't enter the same Player twice.
    CHECK_THROWS(Game(aviya, aviya));

    //Test_: check that 1 player cant play at 2 difference game at the same time.
    CHECK_THROWS(Game(aviya, bob));

    game.playAll(); // end the game.

    //Test_: check that the game is realy end.
    CHECK( ( (alice.stacksize() == 0 ) && (bob.stacksize() == 0) ) );

    //Test_: check that after the game finised the Player is free and can play a new game.
    CHECK_NOTHROW(Game(aviya, bob));
}


TEST_CASE("In the game 1")
{
    Player alice("Alice");
    Player bob("Bob");
    Game game(alice, bob);
    game.playTurn();

    // Test_: can printLog() after played some turns.
    CHECK_NOTHROW(game.printLog());
    
    // Test_: can printLastTurn() after playing some turns.
    CHECK_THROWS(game.printLastTurn());

    // Test_: after play turn chek that one of the data membes is changed ->
    //                       Player_1.cardsTaken() || Player_2.cardsTaken(). 
    CHECK( ( (alice.cardesTaken() > 0) || (bob.cardesTaken() > 0) ));

    // Test_: paly turns to the end of the game and check Player_1.stackSize() == Player_1.stackSize().
    while ( (alice.stacksize() > 0) || (bob.stacksize() > 0) )
    {
        game.playTurn();
        CHECK( alice.stacksize() == bob.stacksize() );
    }
    // Test_: finish the game and after that check that Player_1.stackSize() == Player_2.stackSize() == 0.
    CHECK( ( (alice.stacksize() == 0 ) && (bob.stacksize() == 0) ) );

}

TEST_CASE("In the game 2")
{
    Player alice("Alice");
    Player bob("Bob");
    Game game(alice, bob);
     game.playAll();

    // Test_: playAll() and after that check that Player_1.stackSize() == Player_2.stackSize() == 0.
    CHECK( ( (alice.stacksize() == 0 ) && (bob.stacksize() == 0) ) );

    // Test_: palyAll() and after that palyTurn(), catch exception.
    CHECK_THROWS(game.playTurn());

    // Test_: playAll() and after that print winner.
    CHECK_NOTHROW( game.printWiner() );

}

