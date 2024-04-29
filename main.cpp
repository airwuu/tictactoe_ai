#include <iostream>
#include "GameState.h"
#include "WeakAI.h"
#include "StrongAI.h"
#include "PlayerCalls.h"
#include "mainMenu.h"

using namespace std;

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
    int keepGoing = 0;
    system("clear");
    mainMenu menu;

    // Run Game Type
    // while(gameType != 6){
    //     menu.runGameType(gameType, game);
    // }

    // Loop the game 
    // do { 
    //     // print menu 
    //     system("clear");
    //     cout << menu << endl;
    //     menu.runGameType(gameType, game);
    //     keepGoing = menu.willContinue();
    // } while(keepGoing == 0);

    while(keepGoing == 0) { 
        // reset game
        GameState newGame;
        game = newGame;

        int gameType;
        gameType = theMenu(menu);
        system("clear");
        cout << menu << endl;
        menu.runGameType(gameType, game, menu);

        keepGoing = menu.willContinue();
    }
    return 0;
}