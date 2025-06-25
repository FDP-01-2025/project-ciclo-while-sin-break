#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
using namespace std;

// Inicializa todo el tablero con '~' (agua sin disparar)
void Initializeboard(char board[10][10]);

// Muestra el tablero en pantalla (puede usarse para debug o turnos)
void displayboard(const char board[10][10]);


// Coloca un barco en el tablero (horizontal o vertical)
bool placeShip(char board[10][10], int row, int col, int size, char direction, char symbol);


#endif