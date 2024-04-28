#include <iostream>
#include "GameState.h"
#include "WeakAI.h"
#include "StrongAI.h"

using namespace std;

// // Weak AI Logic
//i moved it into another file

// Strong AI Logic


// Menu
int menu(){
    int input;

    cout << "===== Tic-Tac-Toe-AI =====" << endl;
    cout << "  1. Two Player" << endl;
    cout << "  2. One Player (Weak AI)" << endl;
    cout << "  3. One Player (Strong AI)" << endl << endl;
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
            //  Node* root = new Node(game);
            // populate(root);
            // Vec move = aiMove(root,0);
            // x = move.x; 
            // y = move.y; 
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

        if (game.currentTurn){

             Node* root = new Node(game);
            populate(root);
            Vec move = aiMove(root,0);
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

// Run game
int main(){
    GameState game;
    int gameType;
    cout<<"hellooooo";
    gameType = menu();

    // Run Game Type
    switch(gameType) {
        case 1:
            game = p2(game);
            break;
        case 2:
            game = p1w(game);
            break;
        case 3:
            game = p1s(game);
            break;
        default:
            return 1;
    }

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