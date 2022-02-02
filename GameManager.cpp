#include "GameManager.h"
#include <random>

Game2048::Game2048(){
    score_ = 0;
    bestScore_ = 0;
}

void Game2048::newGame(){
    score_ = 0;
    //filling board with "empty" values
    for (int i = 0; i < boardSize; ++i)
        for (int j = 0; j < boardSize; ++j)
            board[i][j] = 0;

    emit newGameStarted();
}
