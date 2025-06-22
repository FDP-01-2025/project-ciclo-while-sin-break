#ifndef GAME_HISTORY
#define GAME_HISTORY

#include <fstream>
#include <iostream>

void saveGame(const char board1[10][10], const char board2[10][10], int turn); /*Guarda los tableros
y los turnos en un archivo .txt*/

bool loadGame(char board1[10][10], char board2[10][10], int &turn); /*Carga los tableros y turnos
en un archivo .txt*/

#endif
