#ifndef MAIN_MENU
#define MAIN_MENU

#include <iostream>
#include <cmath>
#include <cstdlib> 

using namespace std;

// Create main menu 
struct mainMenu{ 
    private:
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

    public:
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
        return (xWinsRegular + oWinsRegular) / gamesPlayedRegular;
    }

    // Calculate the tie percentage for the total game mode
    float calculateTiePercentage(){ 
        return tiesRegular / gamesPlayedRegular;
    }

    // Calculate the win percentage for the PVP game mode
    float calculateWinPercentagePVP(){ 
        return (xWinsPVP + oWinsPVP) / gamesPlayedPVP;
    }

    // Calculate the tie percentage for the PVP game mode
    float calculateTiePercentagePVP(){ 
        return tiesPVP / gamesPlayedPVP;
    }

    // Calculate the win percentage for the PvAI game mode
    float calculateWinPercentagePvAI(){ 
        return (xWinsPvAI + oWinsPvAI) / gamesPlayedPvAI;
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
        cout << "Stats have been cleared\n";
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