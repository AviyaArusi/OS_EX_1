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
    Player player("Aviya");
    // Test_1: creat Player and check it not null() --> if we can use some function in playerit  is not null.
    CHECK_NOTHROW(player.stacksize());
    // Test_2: check that Player.cardesTaken() == 0 before entry to any Game.
    CHECK(player.stacksize() == 0);
    // Test_3: check that Player.cardesTaken() == 0 before any playTurn().
    CHECK(player.cardesTaken() == 0);
}


TEST_CASE("Creat Game")
{
    Player alice("Alice");
    Player bob("Bob");
    Game game(alice, bob);
    // Test_: creat Game end check it not null --> if we can use some function from game it is not null.
    // CHECK_NOTHROW(game.printStats());
    // Test_: printLastTurn() before playing any turn and catch exception.
    // CHECK_THROWS(game.printLastTurn());
    // Test_: printLog() before played any turn and catch exception.
    // CHECK_THROWS(game.printLog());
    // Test_: printWinner() before the end of the game and catch exception.
    // CHECK_THROWS(game.printWiner());
    // Tset_:  check for equal number of cards for every player after the start of the game 
    //                                   Player_1.stackSize() == Player_1.stackSize() == 26.
    // CHECK(alice.stacksize() == bob.stacksize());
    // CHECK(alice.stacksize() == 26);
}


TEST_CASE("In the game")
{
    Player alice("Alice");
    Player bob("Bob");
    Game game(alice, bob);
    // Test_: play turn and chek that one of the data membes is changed ->
    //                       Player_1.cardsTaken() || Player_2.cardsTaken(). 
    game.playTurn();
    CHECK( ( (alice.cardesTaken() > 0) || (bob.cardesTaken() > 0) ));

    // Test_: paly 5 turn and check Player_1.stackSize() == Player_1.stackSize().
    for (size_t i = 0; i < 5; i++)
    {
        game.playTurn();
        CHECK( alice.stacksize() == bob.stacksize() );

    game.playAll();
    // Test_: playAll() and after that check that Player_1.stackSize() == Player_2.stackSize() == 0.
    CHECK(alice.stacksize() == bob.stacksize() );
    CHECK(alice.stacksize() == 0);
    // Test_: palyAll() and after that palyTurn(), catch exception.
    CHECK_NOTHROW(game.playTurn());
    }
    
}


// Test_: play some turns then check if Player_1.stackSize() + Player_1.cardsTaken() +
//                                      Player_2.stackSize() + Player_2.cardsTaken() == 52.



// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 

// Test_: 