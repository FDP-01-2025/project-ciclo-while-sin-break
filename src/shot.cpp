#include "shot.h"
#include <iostream>

using namespace std;

// Esta funcion la utlizamos cuando el jugador realiza un disparo.
// Le damos la fila y la columna donde le quiere dar.
// Si hay un barco "D" y le pego lo marcaremos con una x.
// Si no hay barco o solo hay agua marcaremos la casilla con una o para indicar que fallo su disparo.
// Si habia tirado en ese lugar antes indicaremos que no es valida y le pediremos que vuelva a ingresar otra coordenada.

bool makeshot(char board[10][10], int row, int col)
{
    if (board[row][col] == 'B')
    {
        board[row][col] = 'X'; // Le disparo a un barco, lo marcamos con una X
        return true;
    }
else if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Ya disparaste en esta posición." << endl; // Ya habías tirado ahí
        return false;
    }
else
{
    board[row][col] = 'O'; // No había nada, fue agua 
        return false;
}
}
//Se revisa  si aún quedan barcos sin destruir en el tablero.
// Buscamos en todo el tablero algun barco vivo o una 'B'.
// Si no hay nada el jugador ha perdido.
bool shipsRemaining(char board[10][10])
{
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            if (board[row][col] == 'B') {
                return true; // Todavía hay barcos en el tablero
            }
        }
    }
    return false; // Ya no quedan barcos
}