#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
using namespace std;

// Inicializa todo el tablero con '-' (agua sin disparar)
void Initializeboard(char board[10][10]);

// Muestra el tablero en pantalla (puede usarse para debug o turnos)
void displayboard(const char board[10][10]);

// Coloca un barco en el tablero (horizontal o vertical)
bool placeShip(char board[10][10], int row, int col, int size, char direction, char symbol);

// Coloca todos los barcos del jugador preguntando a    l usuario
void placeShips(char board[10][10]);

//Coloca los barcos aleatoreamente de la pc
void placeShipRandom(char board[10][10]);

// verifica si un jugador ya perdio
bool hasLost(char board[10][10]);

#endif
