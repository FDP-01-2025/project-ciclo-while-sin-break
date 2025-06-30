#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include "board.h"
#include "shot.h"
#include <iostream>
using namespace std;

// crea una partida multijugador.
void startMultiplayer();

void continueMultiplayer(char board1[10][10], char board2[10][10],
                         char view1[10][10], char view2[10][10],
                         string name1, string name2, int turn);
#endif