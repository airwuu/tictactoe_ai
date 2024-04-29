#include <iostream>
#include "GameState.h"
#include "WeakAI.h"
#include "StrongAI.h"
#include "PlayerCalls.h"
#include "mainMenu.h"

using namespace std;

// // Weak AI Logic
//i moved it into another file

// Strong AI Logic


// Menu
int theMenu(mainMenu menu){
    int input;
    cout << menu << endl;
    cin >> input;

    return input;
}

// Run game
int main(){
    GameState game;
    int gameType;
    system("clear");
    mainMenu menu;
    gameType = theMenu(menu);

    // Run Game Type
    // while(gameType != 6){
    //     menu.runGameType(gameType, game);
    // }

    // Loop the game 
    do { 
        // print menu 
        cout << menu << endl;
        menu.runGameType(gameType, game);
    } while(gameType != 6);

    // After Game Finishes
    system("clear");
    cout << game << endl;
    cout << endl;
    if (game.hasWon(0)){
        cout << "Player X has won" << endl;
    }

    else if (game.hasWon(1)){
        cout << "Player O has won" << endl;
    }
    else {
        cout << "It's a tie" << endl;
    }
    return 0;
}