#include "multiplayer.h"
#include "achievements.h"
#include "save_load.h"
#include "board.h"
#include "shot.h"
#include "music.h"
#include "language.h"
#include <iostream>
using namespace std;

void startMultiplayer()
{
    playCalmMusic(); // Música tranquila al inicio

    char player1Board[10][10], player2Board[10][10];
    char viewBoard1[10][10], viewBoard2[10][10];
    string name1, name2;
    int turn = 1;

    cout <<getText("name1")<<endl;
    cout << getText("name1");
    cin >> name1;
    cout << getText("name2")<<endl;
    cin >> name2;

    Initializeboard(player1Board);
    Initializeboard(player2Board);
    Initializeboard(viewBoard1);
    Initializeboard(viewBoard2);

    cout << name1 << getText("p_ships") << endl;
    placeShips(player1Board);

    cout << name2 << getText("p_ships") << endl;
    placeShips(player2Board);

    bool gameOver = false;
    int hitConsecutive1 = 0, hitConsecutive2 = 0;

    while (!gameOver)
    {
        string currentPlayer;
        char (*myBoard)[10];
        char (*enemyBoard)[10];
        char (*myView)[10];
        int *myConsecutiveHits;

        if (turn % 2 != 0)
        {
            currentPlayer = name1;
            myBoard = player1Board;
            enemyBoard = player2Board;
            myView = viewBoard1;
            myConsecutiveHits = &hitConsecutive1;
        }
        else
        {
            currentPlayer = name2;
            myBoard = player2Board;
            enemyBoard = player1Board;
            myView = viewBoard2;
            myConsecutiveHits = &hitConsecutive2;
        }

        int shipsLeft = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (enemyBoard[i][j] == 'B')
                    shipsLeft++;

        if (shipsLeft == 1)
        {
            playSuspenseMusic(); // Música de suspenso si queda un solo barco
        }

        cout << "\n" << currentPlayer << getText("turn_") << turn << ")" << endl;
        displayboard(myView);

        string input;
        cout << getText("coordinates") << endl;
        cin >> input;

        if (input.length() == 1 && (input[0] == 'Z' || input[0] == 'z'))
        {
            save_Game(player1Board, player2Board, viewBoard1, viewBoard2, name1, name2, turn);
            cout << getText("g_c");
            stopMusic();
            return;
        }

        if (input.length() < 2 || input.length() > 3)
        {
            cout << getText("input_lng") << endl;
            continue;
        }

        char rowChar = toupper(input[0]);
        if (rowChar < 'A' || rowChar > 'J')
        {
            cout << getText("invalid_r")<<endl;
            cout << getText("invalid_r") << endl;
            continue;
        }
        int row = rowChar - 'A';

        int col;
        try
        {
            col = stoi(input.substr(1)) - 1;
        }
        catch (...)
        {
            cout << getText("invalid_c") << endl;
            continue;
        }

        if (col < 0 || col > 9)
        {
            cout << getText("col_rang") << endl;
            continue;
        }

        bool hit = makeshot(enemyBoard, row, col);
        myView[row][col] = hit ? 'X' : 'O';

        int shipSize = 0;
        int shipsDestroyed = 0;

        if (hit)
        {
            cout << getText("hit") << endl;
            (*myConsecutiveHits)++;

            // Verificar si es un barco de 1 casilla
            bool isSingleShip = true;

            if (row > 0 && enemyBoard[row - 1][col] == 'B') isSingleShip = false;
            if (row < 9 && enemyBoard[row + 1][col] == 'B') isSingleShip = false;
            if (col > 0 && enemyBoard[row][col - 1] == 'B') isSingleShip = false;
            if (col < 9 && enemyBoard[row][col + 1] == 'B') isSingleShip = false;

            if (isSingleShip)
                shipSize = 1;
        }
        else
        {
            cout << getText("miss") << endl;
            *myConsecutiveHits = 0;
        }

        bool playerWin = hasLost(enemyBoard);

        checkAchievements(currentPlayer, hit, *myConsecutiveHits, turn, playerWin, false, shipsDestroyed, shipSize);

        if (playerWin)
        {
            cout << currentPlayer << getText("win") << endl;
            stopMusic();
            gameOver = true;
        }

        turn++;
    }
}

void continueMultiplayer(char player1Board[10][10], char player2Board[10][10],
                         char viewBoard1[10][10], char viewBoard2[10][10],
                         string name1, string name2, int turn)
{
    playCalmMusic(); // Música tranquila al cargar partida

    bool gameOver = false;
    int hitConsecutive1 = 0, hitConsecutive2 = 0;

    while (!gameOver)
    {
        string currentPlayer;
        char (*myBoard)[10];
        char (*enemyBoard)[10];
        char (*myView)[10];
        int *myConsecutiveHits;

        if (turn % 2 != 0)
        {
            currentPlayer = name1;
            myBoard = player1Board;
            enemyBoard = player2Board;
            myView = viewBoard1;
            myConsecutiveHits = &hitConsecutive1;
        }
        else
        {
            currentPlayer = name2;
            myBoard = player2Board;
            enemyBoard = player1Board;
            myView = viewBoard2;
            myConsecutiveHits = &hitConsecutive2;
        }

        int shipsLeft = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (enemyBoard[i][j] == 'B')
                    shipsLeft++;

        if (shipsLeft == 1)
        {
            playSuspenseMusic();
        }


        cout << "\n" << currentPlayer << getText("turn_") << turn << ")"<<endl;

        displayboard(myView);

        string input;
        cout << getText("coordinates")<<endl;
        cin >> input;

        if (input.length() == 1 && (input[0] == 'Z' || input[0] == 'z'))
        {
            save_Game(player1Board, player2Board, viewBoard1, viewBoard2, name1, name2, turn);
            cout << getText("g_c") << endl;
            stopMusic();
            return;
        }

        if (input.length() < 2 || input.length() > 3)
        {
            cout << getText("input_lng") << endl;
            continue;
        }

        char rowChar = toupper(input[0]);
        if (rowChar < 'A' || rowChar > 'J')
        {
            cout << getText("invalid_r") << endl;
            continue;
        }
        int row = rowChar - 'A';

        int col;
        try
        {
            col = stoi(input.substr(1)) - 1;
        }
        catch (...)
        {
            cout << getText("invalid_c") << endl;
            continue;
        }

        if (col < 0 || col > 9)
        {
            cout << getText("col_rang") << endl;
            continue;
        }

        bool hit = makeshot(enemyBoard, row, col);
        myView[row][col] = hit ? 'X' : 'O';

        int shipSize = 0;
        int shipsDestroyed = 0;

        if (hit)
        {
            cout << getText("hit") << endl;
            (*myConsecutiveHits)++;

            // Verificar si es un barco de 1 casilla
            bool isSingleShip = true;

            if (row > 0 && enemyBoard[row - 1][col] == 'B') isSingleShip = false;
            if (row < 9 && enemyBoard[row + 1][col] == 'B') isSingleShip = false;
            if (col > 0 && enemyBoard[row][col - 1] == 'B') isSingleShip = false;
            if (col < 9 && enemyBoard[row][col + 1] == 'B') isSingleShip = false;

            if (isSingleShip)
                shipSize = 1;
        }
        else
        {
            cout << getText("miss") << endl;
            *myConsecutiveHits = 0;
        }

        bool playerWin = hasLost(enemyBoard);

        checkAchievements(currentPlayer, hit, *myConsecutiveHits, turn, playerWin, false, shipsDestroyed, shipSize);

        if (playerWin)
        {
            cout << currentPlayer << getText("win") << endl;
            stopMusic();
            gameOver = true;
        }

        turn++;
    }
}