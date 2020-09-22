#ifndef GAME2048_H
#define GAME2048_H

#include <iostream>
#include <utility>
#include <QVector>
#include <QTime>
#include <QObject>

class Game2048: public QObject
{
    Q_OBJECT

public:
    int dirCol[4] = {1 , 0, -1, 0}
       ,dirRow[4] = {0 , 1, 0, -1};
    int board[4][4];
    int score_
       ,bestScore_;



    Game2048();
    void newGame();
    void applyMove(int);
    bool canMove(int, int, int, int);
    void mergeCells(int, int, int, int);
    void updateScore(int);
    void addPiece();
    bool boardIsFull();
    std::pair<int, int> generateUnoccupiedPossition();


signals:
    Q_SIGNAL void endGame();
    Q_SIGNAL void newGameStarted();

};

#endif // GAME2048_H
