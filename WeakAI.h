#ifndef WEAKAI_H
#define WEAKAI_H
#include <iostream>
#include "GameState.h"
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
#endif