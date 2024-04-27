#include <iostream>
#include <cmath>
#include <cstdlib>
#include "GameState.h"

using namespace std;

//This the main menu 
void displayMenu() {
    cout << "Welcome to Tic-Tac-Toe" << endl;
    // cout <<"-----------------------"<< endl;
    cout << "~~~~~~ Main Menu ~~~~~~" << endl;
    cout << "----------------------" << endl;
    cout << "   Select a Game Mode" << endl;
    cout << "----------------------" << endl;
    cout << "1. Regular Game" << endl;
    cout << "2. Person vs Person" << endl;
    cout << "3. Person vs AI" << endl;
    cout << "4. View Game Statistics" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

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

void playRegularGame(int& ties, int& xWins, int& oWins, int& gamesPlayed) {
    GameState game;
    while (!game.done) {
        system("clear");
        cout << game << endl;

        int x, y;

        if (game.currentTurn) {
            Vec move = validMove(game);
            x = move.x;
            y = move.y;
        } else {
            cout << endl;
            cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): ";
            cin >> x >> y;
        }

        game.play(x, y);
    }

    system("clear");
    cout << game << endl;
    cout << endl;
    if (game.hasWon(0)) {
        cout << "Player X has won" << endl;
        xWins++;
    } else if (game.hasWon(1)) {
        cout << "Player O has won" << endl;
        oWins++;
    } else {
        cout << "It's a tie" << endl;
        ties++;
    }
    gamesPlayed++;
    cout << "Press Enter to continue...";
    cin.ignore(); // Clear newline character
    cin.get();    // Wait for Enter key
}

void playPersonVsPerson(int& ties, int& xWins, int& oWins, int& gamesPlayed) {
    GameState game;
    while (!game.done) {
        system("clear");
        cout << game << endl;

        int x, y;

        cout << endl;
        cout << "Enter move for (" << (!game.currentTurn ? "X" : "O") << "): ";
        cin >> x >> y;

        game.play(x, y);
    }

    system("clear");
    cout << game << endl;
    cout << endl;
    if (game.hasWon(0)) {
        cout << "Player X has won" << endl;
        xWins++;
    } else if (game.hasWon(1)) {
        cout << "Player O has won" << endl;
        oWins++;
    } else {
        cout << "It's a tie" << endl;
        ties++;
    }
    gamesPlayed++;
    cout << "Press Enter to continue...";
    cin.ignore(); 
    cin.get();    
}


//The player vs AI isnt a good one I have it just printing out the AI wins you cant actually play the game 
//(SO IGNORE GAME)
void playPersonVsAI(int& ties, int& xWins, int& oWins, int& gamesPlayed) {
    GameState game;
    while (!game.done) {
        system("clear");
        cout << game << endl;

        int x, y;

        if (game.currentTurn) {
            Vec move = validMove(game);
            x = move.x;
            y = move.y;
        } else {
            cout << endl;
            cout << "AI's move:" << endl;
            
            x = rand() % game.size;
            y = rand() % game.size;
        }

        game.play(x, y);
    }

    system("clear");
    cout << game << endl;
    cout << endl;
    if (game.hasWon(0)) {
        cout << "Player X has won" << endl;
        xWins++;
    } else if (game.hasWon(1)) {
        cout << "AI has won" << endl;
        oWins++;
    } else {
        cout << "It's a tie" << endl;
        ties++;
    }
    gamesPlayed++;
    cout << "Press Enter to continue...";
    cin.ignore(); 
    cin.get();   
}

// This is for the win percentages this does the math
float calculateWinPercentage(int wins, int totalGames) {
    if (totalGames == 0) return 0.0f;
    return ceil((wins / static_cast<float>(totalGames)) * 100);
}

// this is for the Tie 
float calculateTiePercentage(int ties, int totalGames) {
    if (totalGames == 0) return 0.0f;
    return ceil((ties / static_cast<float>(totalGames)) * 100);
}

void viewStatistics(int& tiesRegular, int& xWinsRegular, int& oWinsRegular, int& gamesPlayedRegular,
                    int& tiesPvP, int& xWinsPvP, int& oWinsPvP, int& gamesPlayedPvP,
                    int& tiesPvAI, int& xWinsPvAI, int& oWinsPvAI, int& gamesPlayedPvAI) {
    int choice;
    do {
        system("clear");
        cout << "Select Game Mode Statics:" << endl;
        cout <<"--------------------------" << endl;
        cout << "1. Regular Game" << endl;
        cout << "2. Person vs Person" << endl;
        cout << "3. Person vs AI" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        system("clear"); 

        switch (choice) {
            case 1:
                cout << "Game Stats -Regular Game-:" << endl;
                cout << "Total Games Played: " << gamesPlayedRegular << endl;
                cout << "X Wins: " << xWinsRegular << " (" << calculateWinPercentage(xWinsRegular, gamesPlayedRegular) << "%)" << endl;
                cout << "O Wins: " << oWinsRegular << " (" << calculateWinPercentage(oWinsRegular, gamesPlayedRegular) << "%)" << endl;
                cout << "Ties: " << tiesRegular << " (" << calculateTiePercentage(tiesRegular, gamesPlayedRegular) << "%)" << endl;
                break;
            case 2:
                cout << "Game Stats -Person vs Person-:" << endl;
                cout << "Total Games Played: " << gamesPlayedPvP << endl;
                cout << "X Wins: " << xWinsPvP << " (" << calculateWinPercentage(xWinsPvP, gamesPlayedPvP) << "%)" << endl;
                cout << "O Wins: " << oWinsPvP << " (" << calculateWinPercentage(oWinsPvP, gamesPlayedPvP) << "%)" << endl;
                cout << "Ties: " << tiesPvP << " (" << calculateTiePercentage(tiesPvP, gamesPlayedPvP) << "%)" << endl;
                break;
            case 3:
                cout << "Game Stats -Person vs AI-:" << endl;
                cout << "Total Games Played: " << gamesPlayedPvAI << endl;
                cout << "X Wins: " << xWinsPvAI << " (" << calculateWinPercentage(xWinsPvAI, gamesPlayedPvAI) << "%)" << endl;
                cout << "O Wins: " << oWinsPvAI << " (" << calculateWinPercentage(oWinsPvAI, gamesPlayedPvAI) << "%)" << endl;
                cout << "Ties: " << tiesPvAI << " (" << calculateTiePercentage(tiesPvAI, gamesPlayedPvAI) << "%)" << endl;
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
        cout << "Press Enter to continue...";
        cin.ignore(); // Clear newline
        cin.get();    // Wait for Enter
    } while (true);
}

int main() {
    int choice;
    int gamesPlayedRegular = 0;
    int xWinsRegular = 0;
    int oWinsRegular = 0;
    int tiesRegular = 0;
    int gamesPlayedPvP = 0;
    int xWinsPvP = 0;
    int oWinsPvP = 0;
    int tiesPvP = 0;
    int gamesPlayedPvAI = 0;
    int xWinsPvAI = 0;
    int oWinsPvAI = 0;
    int tiesPvAI = 0;

    do {
        system("clear");
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                playRegularGame(tiesRegular, xWinsRegular, oWinsRegular, gamesPlayedRegular);
                break;
            case 2:
                playPersonVsPerson(tiesPvP, xWinsPvP, oWinsPvP, gamesPlayedPvP);
                break;
            case 3:
                playPersonVsAI(tiesPvAI, xWinsPvAI, oWinsPvAI, gamesPlayedPvAI);
                break;
            case 4:
                viewStatistics(tiesRegular, xWinsRegular, oWinsRegular, gamesPlayedRegular,
                               tiesPvP, xWinsPvP, oWinsPvP, gamesPlayedPvP,
                               tiesPvAI, xWinsPvAI, oWinsPvAI, gamesPlayedPvAI);
                break;
            case 5:
                cout << "Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
