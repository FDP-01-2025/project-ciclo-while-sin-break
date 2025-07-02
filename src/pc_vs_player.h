#ifndef PC_VS_PLAYER_H
#define PC_VS_PLAYER_H

#include "board.h"
#include "shot.h"
#include <iostream>
using namespace std;

void playerVsPC();

void  ContinuePcVsPlayer(char playerBoard[10][10], char pcBoard[10][10],
                        char viewBoardPlayer[10][10], char viewBoardPc[10][10],
                        std::string playerName, int turn);

#endif