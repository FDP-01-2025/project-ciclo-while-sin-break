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
        cout << col + 1 << "  "; // Mostrar números columna arriba
    }
    cout << endl;

    for (int row = 0; row < 10; row++)
    {
        cout << char('A' + row) << " "; // Letras fila al lado

        for (int col = 0; col < 10; col++)
        {
            cout << board[row][col] << "  "; // Mostrar celda
        }
        cout << endl;
    }
}

bool placeShip(char board[10][10], int row, int col, int size, char direction, char symbol)
{
    if (direction == 'H')
    {
        if (col + size > 10)
            return false;
        for (int i = 0; i < size; i++)
        {
            if (board[row][col + i] != '-')
                return false;
        }
        for (int i = 0; i < size; i++)
        {
            board[row][col + i] = symbol;
        }
    }
    else if (direction == 'V')
    {
        if (row + size > 10)
            return false;
        for (int i = 0; i < size; i++)
        {
            if (board[row + i][col] != '-')
                return false;
        }
        for (int i = 0; i < size; i++)
        {
            board[row + i][col] = symbol;
        }
    }
    else
    {
        return false;
    }

    return true;
}

void placeShips(char board[10][10])
{
    int shipSizes[] = {5, 2, 2, 1, 1};
    char shipSymbols[] = {'A', 'B', 'C', 'D', 'E'};

    for (int i = 0; i < 5; i++)
    {
        int row, col;
        char direction;
        bool placed = false;

        cout << "Colocando barco de tamaño " << shipSizes[i] << " (símbolo '" << shipSymbols[i] << "')\n";

        while (!placed)
        {
            cout << "Ingresa fila inicial (A-J): ";
            char rowChar;
            cin >> rowChar;
            row = toupper(rowChar) - 'A';

            cout << "Ingresa columna inicial (1-10): ";
            cin >> col;
            col -= 1; // Para índice 0-based

            cout << "Dirección (H para horizontal, V para vertical): ";
            cin >> direction;
            direction = toupper(direction);

            if (row < 0 || row >= 10 || col < 0 || col >= 10)
            {
                cout << "Coordenadas inválidas. Intenta de nuevo.\n";
                continue;
            }

            if (direction != 'H' && direction != 'V')
            {
                cout << "Dirección inválida. Usa H o V.\n";
                continue;
            }

            placed = placeShip(board, row, col, shipSizes[i], direction, shipSymbols[i]);

            if (!placed)
            {
                cout << "No se pudo colocar el barco ahí. Intenta otra posición.\n";
            }
            else
            {
                displayboard(board);
            }
        }
    }
}
bool hasLost(char board[10][10])
{
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            if (board[i][j] == 'B') // ← si queda una parte de barco viva...
                return false;       // ...entonces no ha perdido aún
    return true;                    // No quedan barcos: ¡perdió!
}
