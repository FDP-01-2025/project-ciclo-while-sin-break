#ifndef DISPAROS_H
#define DISPAROS_H

#include <iostream>
using namespace std;

// Esta función marca un disparo en el tablero: 'X' si acierta, 'O' si falla.
// Devuelve true si fue impacto, false si fue agua o repetido.
bool makeshot(char board[10][10], int fila, int columna);

// Esta función verifica si quedan barcos ('B') en el tablero.
bool shipsRemaining(char board[10][10]);

#endif