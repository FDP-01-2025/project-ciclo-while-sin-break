#include "shot.h"
#include "language.h"
#include <iostream>

using namespace std;

bool makeshot(char board[10][10], int row, int col)
{
    // Verificamos si ya disparó ahí antes
    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        cout << getText(shot_po) << endl;
        return false;
    }


    if (board[row][col] == 'B')
    {
        board[row][col] = 'X';
        return true;
    }

    
    board[row][col] = 'O';
    return false;
}

bool shipsRemaining(char board[10][10])
{
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            if (board[row][col] == 'B')
            {
                return true; // Quedan barcos
            }
        }
    }
    return false; // No quedan barcos
}
