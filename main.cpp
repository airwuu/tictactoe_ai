#include <iostream>
#include "GameState.h"
#include "WeakAI.h"
#include "StrongAI.h"
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

        if (game.currentTurn){
            cout<<"Current turn count: "<<game.turnCount<<"\n";
            if((game.turnCount == 1)){
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
    return game;
}

// Run game
int main(){
    GameState game;
    int gameType;
    system("clear");
    mainMenu menu;
    gameType = theMenu(menu);

    // Run Game Type
    switch(gameType) {
        case 1:
            game = p2(game);
            menu.enterToContinue();
            break;
        case 2:
            game = p1w(game);
            menu.enterToContinue();
            break;
        case 3:
            game = p1s(game);
            menu.enterToContinue();
            break;
        case 4: // show game stats
            menu.gameStats();
            menu.enterToContinue();
            break;
        case 5: // clear game stats
            menu.clearStats();
            menu.enterToContinue();
            break;
        case 6:
            cout << "Exiting. . . Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            menu.enterToContinue();
            break;
    } while (gameType != 5);

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