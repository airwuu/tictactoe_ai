#ifndef MAIN_MENU
#define MAIN_MENU

#include <iostream>
#include <cmath>
#include <cstdlib> 
#include "PlayerCalls.h"
#include "GameState.h"
#include "StrongAI.h"
#include "WeakAI.h"

using namespace std;
// outline for mainMenu struct
struct mainMenu;


// Create main menu 
struct mainMenu{ 
    int choice; 
    int gamesPlayedRegular;
    int xWinsRegular;
    int oWinsRegular;
    int tiesRegular;
    int gamesPlayedPVP;
    int xWinsPVP;
    int oWinsPVP;
    int tiesPVP;
    int gamesPlayedPvAI; 
    int xWinsPvAI;
    int oWinsPvAI;
    int tiesPvAI;

    // Create Constructor
    mainMenu(){ 
        choice = 0;
        gamesPlayedRegular = 0;
        xWinsRegular = 0;
        oWinsRegular = 0;
        tiesRegular = 0;
        gamesPlayedPVP = 0;
        xWinsPVP = 0;
        oWinsPVP = 0;
        tiesPVP = 0;
        gamesPlayedPvAI = 0;
        xWinsPvAI = 0;
        oWinsPvAI = 0;
        tiesPvAI = 0;
    }

    // Calculate the win percentage for the total game mode
    float calculateWinPercentage(){ 
        return xWinsRegular / gamesPlayedRegular;
    }

    // Calculate the tie percentage for the total game mode
    float calculateTiePercentage(){ 
        return tiesRegular / gamesPlayedRegular;
    }

    // Calculate the win percentage for the PVP game mode
    float calculateWinPercentagePVP(){ 
        return xWinsPVP / gamesPlayedPVP;
    }

    // Calculate the tie percentage for the PVP game mode
    float calculateTiePercentagePVP(){ 
        return tiesPVP / gamesPlayedPVP;
    }

    // Calculate the win percentage for the PvAI game mode
    float calculateWinPercentagePvAI(){ 
        return xWinsPvAI / gamesPlayedPvAI;
    }

    // Calculate the tie percentage for the PvAI game mode
    float calculateTiePercentagePvAI(){ 
        return tiesPvAI / gamesPlayedPvAI;
    }

    // Clear Stats
    void clearStats(){ 
        system("clear");
        gamesPlayedRegular = 0;
        xWinsRegular = 0;
        oWinsRegular = 0;
        tiesRegular = 0;
        gamesPlayedPVP = 0;
        xWinsPVP = 0;
        oWinsPVP = 0;
        tiesPVP = 0;
        gamesPlayedPvAI = 0;
        xWinsPvAI = 0;
        oWinsPvAI = 0;
        tiesPvAI = 0;
        cout << "Stats have been cleared. . .\n";
    }

    // get total games played
    int getTotalGamesPlayed(){ 
        return gamesPlayedRegular;
    }

    // get x wins total
    int getXWinsTotal(){ 
        return xWinsRegular;
    }

    // get o wins total
    int getOWinsTotal(){ 
        return oWinsRegular;
    }

    // get total ties
    int getTiesRegular(){ 
        return tiesRegular;
    }

    // get games played for pvp
    int getGamesPlayedPVP(){ 
        return gamesPlayedPVP;
    }

    // get x wins for pvp
    int getXWinsPVP(){ 
        return xWinsPVP;
    }

    // get o wins for pvp
    int getOWinsPVP(){ 
        return oWinsPVP;
    }

    // get ties pvp
    int getTiesPVP(){ 
        return tiesPVP;
    }

    // get games played for PvAI 
    int getGamesPlayedPvAI(){ 
        return gamesPlayedPvAI;
    }

    // get x wins for PvAI
    int getXWinsPvAI(){ 
        return xWinsPvAI;
    }

    // get o wins for PvAI
    int getOWinsPvAI(){ 
        return oWinsPvAI;
    }

    // ties for PvAI
    int getTiesPvAI(){ 
        return tiesPvAI;
    }

    // display gameStats
    void gameStats(){ 
        system("clear");
        cout << "Game Statistics" << endl;
        cout << "----------------" << endl;
        cout << "Total Games Played: " << gamesPlayedRegular << endl;
        cout << "X Wins: " << xWinsRegular << endl;
        cout << "O Wins: " << oWinsRegular << endl;
        cout << "Ties: " << tiesRegular << endl;
        cout << "X Win Percentage: " << calculateWinPercentage() << endl;
        cout << "Tie Percentage: " << calculateTiePercentage() << endl;
        cout << "----------------" << endl;
        cout << "PVP Games Played: " << gamesPlayedPVP << endl;
        cout << "X Wins: " << xWinsPVP << endl;
        cout << "O Wins: " << oWinsPVP << endl;
        cout << "Ties: " << tiesPVP << endl;
        cout << "X Win Percentage: " << calculateWinPercentagePVP() << endl;
        cout << "Tie Percentage: " << calculateTiePercentagePVP() << endl;
        cout << "----------------" << endl;
        cout << "PvAI Games Played: " << gamesPlayedPvAI << endl;
        cout << "X Wins: " << xWinsPvAI << endl;
        cout << "O Wins: " << oWinsPvAI << endl;
        cout << "Ties: " << tiesPvAI << endl;
        cout << "X Win Percentage: " << calculateWinPercentagePvAI() << endl;
        cout << "Tie Percentage: " << calculateTiePercentagePvAI() << endl;
        cout << "----------------" << endl;
    
    }

    // enter to continue function
    int willContinue(){ 
        int playerChoice;
        cout << "Type 1 to exit or any other number to continue: ";
        cin >> playerChoice;
        if(playerChoice == 1){
            exit(0);
            return 1;
        }
        return 0;
    }

    // run game type conditional
    void runGameType(int gameType, GameState& game, mainMenu& menu){ 
        switch(gameType) {
            case 1:
                game = p2(game);
                // update stats
                gamesPlayedRegular++;
                gamesPlayedPVP++;
                if(game.hasWon(0)){
                    xWinsRegular++;
                    xWinsPVP++;
                }
                else if(game.hasWon(1)){
                    oWinsRegular++;
                    oWinsPVP++;
                }
                else{
                    tiesRegular++;
                    tiesPVP++;
                }
                break;
            case 2:
                game = p1w(game);
                // update stats
                gamesPlayedPvAI++;
                gamesPlayedRegular++;
                if(game.hasWon(0)){
                    xWinsRegular++;
                    xWinsPvAI++;
                }
                else if(game.hasWon(1)){
                    oWinsRegular++;
                    oWinsPvAI++;
                }
                else{
                    tiesRegular++;
                    tiesPvAI++;
                }
                break;
            case 3:
                game = p1s(game);
                // update stats
                gamesPlayedPvAI++;
                gamesPlayedRegular++;
                if(game.hasWon(0)){
                    xWinsRegular++;
                    xWinsPvAI++;
                }
                else if(game.hasWon(1)){
                    oWinsRegular++;
                    oWinsPvAI++;
                }
                else{
                    tiesRegular++;
                    tiesPvAI++;
                }
                break;
            case 4: // show game stats
                gameStats();
                break;
            case 5: // clear game stats
                clearStats();
                break;
            case 6:
                system("clear");
                cout << "exiting . . ." << endl;
                // exit program
                exit(0);
                break;
            default: 
                cout << "Invalid choice" << endl;
                break;
        }

    }


    // friend << overloaded operator
    friend ostream& operator<<(ostream& os, mainMenu& menu);

};

// overload menu to print menu
ostream& operator<<(ostream& os, mainMenu& menu){ 
    cout << "Welcome to Tic-Tac-Toe" << endl;
    cout <<"-----------------------"<< endl;
    cout << "~~~~~~ Main Menu ~~~~~~" << endl;
    cout << "----------------------" << endl;
    cout << "   Select a Game Mode" << endl;
    cout << "----------------------" << endl;
    cout << "1. Regular Game" << endl;
    cout << "2. Person vs Person" << endl;
    cout << "3. Person vs AI" << endl;
    cout << "4. View Game Statistics" << endl;
    cout << "5. Clear Game Statistics" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    return os;
}

#endif