#include "board.h"
#include <iostream>

using namespace std;


void Initializeboard(char board[10][10])
{
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            board[row][col] = '-';
        }
    }
}
void displayboard(const char board[10][10])
{
    cout << "  ";
    for (int col = 0; col < 10; col++)  
    {
        cout << col + 1 << "  ";  // Mostrar números columna arriba
    }
    cout << endl;

    for (int row = 0; row < 10; row++)
    {
        cout << char('A' + row) << " ";  // Letras fila al lado

        for (int col = 0; col < 10; col++)
        {
            cout << board[row][col] << "  ";  // Mostrar celda
        }
        cout << endl;
    }
}

bool placeShip(char board[10][10], int row, int col, int size, char direction, char symbol)
{
    if (direction == 'H') {
        if (col + size > 10) return false;
        for (int i = 0; i < size; i++) {
            if (board[row][col + i] != '-') return false;
        }
        for (int i = 0; i < size; i++) {
            board[row][col + i] = symbol;
        }
    } else if (direction == 'V') {
        if (row + size > 10) return false;
        for (int i = 0; i < size; i++) {
            if (board[row + i][col] != '-') return false;
        }
        for (int i = 0; i < size; i++) {
            board[row + i][col] = symbol;
        }
    } else {
        return false;
    }

    return true;
}