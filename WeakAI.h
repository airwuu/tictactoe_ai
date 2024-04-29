#ifndef WEAKAI_H
#define WEAKAI_H
#include <iostream>
#include "GameState.h"
// Weak AI Logic
Vec validMove(GameState game){
    // Traverse through grid
    for (int i = 0; i < game.size; i++){
        for (int j = 0; j < game.size; j++){
            // Selects next empty cell
            if (game.grid[i][j] == -1){
                // make move
                return Vec(i, j);
            }
        }
    }
    // return
    return Vec(0,0);
}
#endif