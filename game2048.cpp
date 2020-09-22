#include "game2048.h"

Game2048::Game2048(){
    score_ = 0;
    bestScore_ = 0;
}
void Game2048::newGame(){

    score_ = 0;
    //filling board with "empty" values
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            board[i][j] = 0;

    //generating first "2"
    addPiece();
    emit newGameStarted();
}
std::pair<int, int> Game2048::generateUnoccupiedPossition(){

    qsrand(QDateTime::currentMSecsSinceEpoch());

    bool generated = false;
    int line, column;

    while(!generated){
        line = qrand() % 4;
        column = qrand() % 4;

        if (0 == board[line][column])
            generated = true;
    }
    return std::make_pair(line, column);
}
void Game2048::addPiece(){
    //randomizing new element possition
    std::pair<int,int> pos = generateUnoccupiedPossition();
    board[pos.first][pos.second] = 2;
}
bool Game2048::canMove(int i, int j, int nextI, int nextJ){

    if (nextI < 0 || nextI >= 4 || nextJ < 0 || nextJ >= 4
        || (board[i][j] != board[nextI][nextJ] && board[nextI][nextJ] != 0))
        return 0;
    return 1;
}
void Game2048::updateScore(int points){
    score_ += points;
    if(score_ > bestScore_)
        bestScore_ = score_;
}
void Game2048::mergeCells(int i, int j, int nextI, int nextJ){

    board[nextI][nextJ] += board[i][j];
    board[i][j] = 0;
}
void Game2048::applyMove(int direction){

    int startRow = 0
            , startColumn = 0
            , lineStep = 1
            , columnStep = 1;

    if (0 == direction || 1 == direction){
        startRow = 3;
        lineStep = -1;
    }
    bool movePossible = 0
        ,canAddPiece = 0;

    do {
        movePossible = 0;
        for (int i = startRow; i>= 0 && i < 4; i+= lineStep)
            for (int j = startColumn; j >= 0 && j < 4 ; j+= columnStep){
                 int nextI = i + dirRow[direction]
                   , nextJ = j + dirCol[direction];

                 if (board[i][j] && canMove(i,j, nextI, nextJ)){
                     mergeCells(i, j, nextI, nextJ);
                     updateScore(board[nextI][nextJ]);
                     movePossible = canAddPiece = true;
                 }
                 else if (boardIsFull()){
                     emit endGame();
                     break;
                 }
            }
      } while (movePossible);

    if (canAddPiece){
       addPiece();
    }
}
bool Game2048::boardIsFull(){
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            if (0 == board[i][j])
                return 0;
    return 1;
}
