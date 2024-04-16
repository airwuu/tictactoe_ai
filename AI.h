#ifndef AI_H
#define AI_H

#include "GameState.h"
#include <iostream>
using namespace std

// Weak AI Logic
Vec validMove(GameState game){
    for (int i = 0; i < game.size; i++){
        for (int j = 0; j < game.size; j++){
            if (game.grid[i][j] == -1){
                return Vec(i, j);
            }
        }
    }
    return Vec(0,0);
}

// Strong AI Logic


// Menu
int menu(){
    int input;

    cout << "===== Tic-Tac-Toe-AI =====" << endl;
    cout << "  1. 2 Player" << endl;
    cout << "  2. 1 Player (Weak AI)" << endl;
    cout << "  3. 1 Player (Strong AI)" << endl << endl;
    cout << "Choice: ";
    cin >> input;

    return input;
}

// 2 Player
GameState p2(GameState game){
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
    return game;
}

// 1 Player Weak
GameState p1w(GameState game){
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
    return game;
}

// 1 Player Strong
GameState p1s(GameState game){
    while(!game.done){ 
        system("clear"); 
        cout << game << endl;

        int x, y; 

        if(game.currentTurn){ 
            Vec move = validMove(game); 
            x = move.x; 
            y = move.y; 
        } 
        else{ 
            cout << endl; 
            cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): "; 
            cin >> x >> y; 
        }
    }
    return game;
}

#endif