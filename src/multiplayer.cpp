#include "multiplayer.h"
#include "achievements.h"
#include "save_load.h"
#include "board.h"
#include "shot.h"
#include <iostream>
using namespace std;

void startMultiplayer()
{
    char player1Board[10][10], player2Board[10][10];
    char viewBoard1[10][10], viewBoard2[10][10];
    string name1, name2;
    int turn = 1;

    cout << "Do you want to load a saved game? (Y/N): ";
    char answer;
    cin >> answer;

    if (toupper(answer) == 'Y')
    {
        load_Game(player1Board, player2Board, viewBoard1, viewBoard2, name1, name2, turn);
        cout << "Game loaded.\n";
    }
    else
    {
        cout << "Player 1 name: ";
        cin >> name1;
        cout << "Player 2 name: ";
        cin >> name2;

        Initializeboard(player1Board);
        Initializeboard(player2Board);
        Initializeboard(viewBoard1);
        Initializeboard(viewBoard2);

        cout << name1 << ", place your ships:\n";
        placeShips(player1Board);

        cout << name2 << ", place your ships:\n";
        placeShips(player2Board);
    }

    bool game_Over = false;
    int hit_consecutive1 = 0, hit_consecutive2 = 0;

    while (!game_Over)
    {
        string currentPlayer = (turn % 2 != 0) ? name1 : name2;
        char (*myBoard)[10] = (turn % 2 != 0) ? player1Board : player2Board;
        char (*enemyBoard)[10] = (turn % 2 != 0) ? player2Board : player1Board;
        char (*myView)[10] = (turn % 2 != 0) ? viewBoard1 : viewBoard2;
        int &myConsecutiveHits = (turn % 2 != 0) ? hit_consecutive1 : hit_consecutive2;

        cout << "\n" << currentPlayer << "'s turn (Turn #" << turn << ")\n";
        displayboard(myView);

        int row, col;
        string input;

        cout << "Enter coordinates (e.g. 3 5) or 'G' to save and exit: ";
        cin >> input;

        if (toupper(input[0]) == 'G')
        {
            save_Game(player1Board, player2Board, viewBoard1, viewBoard2, name1, name2, turn);
            cout << "Game saved.\n";
            return;
        }

        row = stoi(input);
        cin >> col;

        bool hit = makeshot(enemyBoard, row, col);
        myView[row][col] = hit ? 'X' : 'O';

        if (hit)
        {
            cout << "Hit!\n";
            myConsecutiveHits++;
        }
        else
        {
            cout << "Miss...\n";
            myConsecutiveHits = 0;
        }

        bool playerWin = hasLost(enemyBoard);
        bool playerLose = hasLost(myBoard);
        int shipsDestroyed = 0;

        checkAchievements(currentPlayer, hit, myConsecutiveHits, turn, playerWin, playerLose, shipsDestroyed);

        if (playerWin)
        {
            cout << currentPlayer << " wins the game!\n";
            game_Over = true;
        }

        turn++;
    }
}

void continueMultiplayer(char player1Board[10][10], char player2Board[10][10],
                         char viewBoard1[10][10], char viewBoard2[10][10],
                         string name1, string name2, int turn)
{
    bool game_Over = false;
    int hit_consecutive1 = 0, hit_consecutive2 = 0;

    while (!game_Over)
    {
        string currentPlayer = (turn % 2 != 0) ? name1 : name2;
        char (*myBoard)[10] = (turn % 2 != 0) ? player1Board : player2Board;
        char (*enemyBoard)[10] = (turn % 2 != 0) ? player2Board : player1Board;
        char (*myView)[10] = (turn % 2 != 0) ? viewBoard1 : viewBoard2;
        int &myConsecutiveHits = (turn % 2 != 0) ? hit_consecutive1 : hit_consecutive2;

        cout << "\n" << currentPlayer << "'s turn (Turn #" << turn << ")\n";
        displayboard(myView);

        int row, col;
        string input;

        cout << "Enter coordinates (e.g. 3 5) or 'G' to save and exit: ";
        cin >> input;

        if (toupper(input[0]) == 'G')
        {
            save_Game(player1Board, player2Board, viewBoard1, viewBoard2, name1, name2, turn);
            cout << "Game saved.\n";
            return;
        }

        row = stoi(input);
        cin >> col;

        bool hit = makeshot(enemyBoard, row, col);
        myView[row][col] = hit ? 'X' : 'O';

        if (hit)
        {
            cout << "Hit!\n";
            myConsecutiveHits++;
        }
        else
        {
            cout << "Miss...\n";
            myConsecutiveHits = 0;
        }

        bool playerWin = hasLost(enemyBoard);
        bool playerLose = hasLost(myBoard);
        int shipsDestroyed = 0;

        checkAchievements(currentPlayer, hit, myConsecutiveHits, turn, playerWin, playerLose, shipsDestroyed);

        if (playerWin)
        {
            cout << currentPlayer << " wins the game!\n";
            game_Over = true;
        }

        turn++;
    }
}
