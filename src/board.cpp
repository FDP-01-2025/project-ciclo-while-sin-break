#include "board.h"
#include "language.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Inicializa el tablero llenándolo de '-'
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

// Muestra el tablero con colores
void displayboard(const char board[10][10])
{
    cout << "\033[37m  "; // Letras de las columnas en blanco
    for (int col = 0; col < 10; col++)
    {
        cout << col + 1 << "  ";
    }
    cout << "\033[0m" << endl;

    for (int row = 0; row < 10; row++)
    {
        cout << "\033[37m" << char('A' + row) << " \033[0m"; // Letras de filas en blanco
        for (int col = 0; col < 10; col++)
        {
            if (board[row][col] == 'B')
            {
                cout << "\033[34m" << board[row][col] << "  \033[0m"; // Azul para barcos
            }
            else if (board[row][col] == 'X')
            {
                cout << "\033[32m" << board[row][col] << "  \033[0m"; // Verde para aciertos
            }
            else if (board[row][col] == 'O')
            {
                cout << "\033[31m" << board[row][col] << "  \033[0m"; // Rojo para fallos
            }
            else if (board[row][col] == '-')
            {
                cout << "\033[34m" << board[row][col] << "  \033[0m"; // Azul para el agua
            }
            else
            {
                cout << board[row][col] << "  "; // Otros símbolos sin formato
            }
        }
        cout << endl;
    }
}

// Intenta colocar un barco, devuelve true si se colocó correctamente
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

// Permite al jugador colocar manualmente sus barcos pidiendo coordenadas y dirección
void placeShips(char board[10][10])
{
    int shipSizes[] = {5, 2, 2, 1, 1};
    char shipSymbols[] = {'B', 'B', 'B', 'B', 'B'};

    for (int i = 0; i < 5; i++)
    {
        int row, col;
        char direction;
        bool placed = false;

        cout << getText("ship_size") << shipSizes[i] << " and symbol '" << shipSymbols[i] << "'\n";

        while (!placed)
        {
            cout << "Enter the starting coordinate for the ship (e.g., A1): ";
            string input;
            cin >> input;
            cin.clear();
            cin.ignore(1000, '\n');

            if (input.length() < 2 || input.length() > 3)
            {
                cout << "Invalid coordinate format. Try again.\n";
                continue;
            }

            char rowChar = toupper(input[0]);
            if (rowChar < 'A' || rowChar > 'J')
            {
                cout << "Invalid row. Must be A-J.\n";
                continue;
            }
            row = rowChar - 'A';

            try
            {
                col = stoi(input.substr(1)) - 1;
            }
            catch (...)
            {
                cout << "Invalid column number.\n";
                continue;
            }

            if (col < 0 || col >= 10)
            {
                cout << "Column out of range. Must be 1-10.\n";
                continue;
            }

            cout << "Enter direction (H for horizontal, V for vertical): ";
            cin >> direction;
            cin.clear();
            cin.ignore(1000, '\n');

            direction = toupper(direction);

            if (direction != 'H' && direction != 'V')
            {
                cout << "Invalid direction. Enter H or V.\n";
                continue;
            }

            placed = placeShip(board, row, col, shipSizes[i], direction, shipSymbols[i]);

            if (!placed)
            {
                cout << "Cannot place ship here. It overlaps or goes out of bounds. Try again.\n";
            }
            else
            {
                displayboard(board);
            }
        }
    }
}

// Coloca los barcos de forma aleatoria
void placeShipRandom(char board[10][10])
{
    int shipSizes[] = {5, 2, 2, 1, 1};
    char shipSymbols[] = {'B', 'B', 'B', 'B', 'B'};

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        bool placed = false;

        while (!placed)
        {
            int row = rand() % 10;
            int col = rand() % 10;
            char direction = (rand() % 2 == 0) ? 'H' : 'V';

            placed = placeShip(board, row, col, shipSizes[i], direction, shipSymbols[i]);
        }
    }
}

// Verifica si ya perdiste (si quedan barcos en el tablero)
bool hasLost(char board[10][10])
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (board[i][j] == 'B')
                return false;
        }
    }
    return true;
}
