#include "multiplayer.h"
#include "achievements.h"
#include "save_load.h"
#include "board.h"
#include "shot.h"
#include <iostream>
using namespace std;

// cada jugador cuenta con su tablero y gana el que destruya los barcos enemigos primero
void startMultiplayer()
{
    char player1Board[10][10], player2Board[10][10];
    char viewBoard1[10][10], viewBoard2[10][10];
    string name1, name2;
    int turn = 1;
    cout << "Desea cargar una partida anterior? (S/N): ";
    char answer;
    cin >> answer;

    // cargar partida
    if (toupper(answer) == 'S')
    {
        load_Game(player1Board, player2Board, viewBoard1, viewBoard2, name1, name2, turn);
        cout << "Partida cargada exitosamente.\n";
    }
    else
    {
        // Nueva partida
        cout << "Ingrese el nombre del jugador 1: ";
        cin >> name1;
        cout << "Ingrese el nombre del jugador 2: ";
        cin >> name2;

        Initializeboard(player1Board);
        Initializeboard(player2Board);
        Initializeboard(viewBoard1);
        Initializeboard(viewBoard2);

        cout << name1 << ", por favor coloque sus barcos:\n";
        placeShips(player1Board);

        cout << name2 << ", por favor coloque sus barcos:\n";
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

        cout << "\nTurno de " << currentPlayer << " (turno #" << turn << ")\n";
        displayboard(myView);

        int fila, columna;
        string input;

        cout << "Ingrese coordenadas (ej. 3 5) o 'G' para guardar y salir: ";
        cin >> input;

        if (toupper(input[0]) == 'G')
        {
            save_Game(player1Board, player2Board, viewBoard1, viewBoard2, name1, name2, turn);
            cout << "Partida guardada. ¡Hasta la próxima!\n";
            return;
        }

        // Convertimos input a número
        fila = stoi(input);
        cin >> columna;

        // Realizamos el disparo
        bool hit = makeshot(enemyBoard, fila, columna);
        myView[fila][columna] = hit ? 'X' : 'O';

        if (hit)
        {
            cout << "¡Impacto!\n";
            myConsecutiveHits++;
        }
        else
        {
            cout << "Agua...\n";
            myConsecutiveHits = 0;
        }

        // Llamamos a checkAchievements con los parámetros correctos
        bool playerWin = hasLost(enemyBoard);   // enemigo perdió => jugador ganó
        bool playerLose = hasLost(myBoard);     // mi tablero perdido => perdí
        int shipsDestroyed = 0; // Pendiente implementar si quieres contar barcos destruidos

        checkAchievements(currentPlayer, hit, myConsecutiveHits, turn, playerWin, playerLose, shipsDestroyed);

        if (playerWin)
        {
            cout << "¡" << currentPlayer << " ha ganado la partida!\n";
            game_Over = true;
            break;
        }

        turn++;
    }
}
