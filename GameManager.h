#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <utility>
#include <QVector>
#include <QTime>
#include <QObject>

const int boardSize = 4;
const int firstCellValue = 2;
enum direction {down, right, up, left};

class Game2048: public QObject
{
    Q_OBJECT

public:
    int board[boardSize][boardSize];
    int score_
       ,bestScore_;

    Game2048();
    void newGame();

signals:
    Q_SIGNAL void endGame();
    Q_SIGNAL void newGameStarted();
};

#endif // GAMEMANAGER_H
