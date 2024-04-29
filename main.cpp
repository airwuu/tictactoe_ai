#include <iostream>
#include "GameState.h"
#include "WeakAI.h"
#include "StrongAI.h"
#include "PlayerCalls.h"
#include "mainMenu.h"

using namespace std;

// Menu
int theMenu(mainMenu menu){
    // initialize input
    int input;
    // Menu
    cout << menu << endl;
    // get input
    cin >> input;
    // return input
    return input;
}

// Run game
int main(){
    // Initialize GameState
    GameState game;
    // initialize loop variable
    int keepGoing = 0;
    // clear terminal
    system("clear");
    // Initialize mainMenu
    mainMenu menu;

    // LOOP GAME
    while(keepGoing == 0) { 
        // reset game state
        GameState newGame;
        game = newGame;

        // Initialize game type
        int gameType;
        // Call input and calls the menu
        gameType = theMenu(menu);
        // Clear terminal for UI
        system("clear");
        // Displays menu
        cout << menu << endl;
        // Run game type
        menu.runGameType(gameType, game, menu);
        // Allow the user to continue
        keepGoing = menu.willContinue();
    }
    return 0;
}