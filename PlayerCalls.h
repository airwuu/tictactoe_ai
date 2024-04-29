#ifndef PLAYER_CALLS
#define PLAYER_CALLS
#include <iostream>
#include "GameState.h"
#include "StrongAI.h"
#include "WeakAI.h"

using namespace std;

// 2 Player
GameState p2(GameState game, mainMenu menu){
    while(!game.done){
        system("clear");
        cout << game << endl;

        int x, y;

        if (game.currentTurn){
            cout << endl;
            cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): ";
            cin >> x >> y;
        }
        else{
            cout << endl;
            cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): ";
            cin >> x >> y;
        }

        game.play(x, y);
    }
    // display final game state
    system("clear");
    cout << game << endl;

    // Observe who won and update stats
    if (game.hasWon(0)){
        cout << "Player X has won" << endl;
        menu.updateXWinsPVP();
    }

    else if (game.hasWon(1)){
        cout << "Player O has won" << endl;
        menu.updateOWinsPVP();
    }
    else {
        menu.updateTiesPVP();
        cout << "It's a tie" << endl;
    }

    return game;
}

// 1 Player Weak
GameState p1w(GameState game, mainMenu menu){
    while(!game.done){
        system("clear");
        cout << game << endl;

        int x, y;

        if (game.currentTurn){
            Vec move = validMove(game);
            x = move.x;
            y = move.y;
        }
        else{
            cout << endl;
            cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): ";
            cin >> x >> y;
        }

        game.play(x, y);
    }
    // display final game state
    system("clear");
    cout << game << endl;

    // Observe who won and update stats
    if (game.hasWon(0)){
        cout << "Player X has won" << endl;
        menu.updateXWinsPvAI();
    }

    else if (game.hasWon(1)){
        cout << "Player O has won" << endl;
        menu.updateOWinsPvAI();
    }
    else {
        menu.updateTiesPvAI();
        cout << "It's a tie" << endl;
    }

    return game;
}

// 1 Player Strong
GameState p1s(GameState game, mainMenu menu){
    while(!game.done){
        system("clear");
        cout << game << endl;

        int x, y;

        if (game.currentTurn){
            cout<<"Current turn count: "<<game.turnCount<<"\n";
            if(game.turnCount == 1){
                if((game.grid[1][1] != -1)){
                    Vec move = validMove(game);
                    x = move.x;
                    y = move.y;
                }
                else{
                    x = 1;
                    y = 1;
                }
            }
            else{
                Node* root = new Node(game);
                populate(root);
                Vec move = aiMove(root);
                x = move.x; 
                y = move.y; 
            }
            
        }
        else{
            cout << endl;
            cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): ";
            cin >> x >> y;
        }

        game.play(x, y);
    }
    // display final game state
    system("clear");
    cout << game << endl;

    // Observe who won and update stats
    if (game.hasWon(0)){
        cout << "Player X has won" << endl;
        menu.updateXWinsPvAI();
    }

    else if (game.hasWon(1)){
        cout << "Player O has won" << endl;
        menu.updateOWinsPvAI();
    }
    else {
        menu.updateTiesPvAI();
        cout << "It's a tie" << endl;
    }

    return game;
}

#endif