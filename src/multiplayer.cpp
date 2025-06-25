#include "multiplayer.h"
#include "board.h"
#include "shot.h"
#include <iostream>
using namespace std;

// cada jugador cuenta con su tablero y gana el que destruya los barcos enemigos primero
void startMultiplayer()
{
    char player1Board[10][10];
    char player2Board[10][10];

    // inicializamos tableros con la funcion ya creada en board.h
    Initializeboard(player1Board);
    Initializeboard(player2Board);

    // pediremos al usuario que coloque sus barcos (funcion ya creada)
    cout << "jugador 1 por favor coloque sus barcos: " << endl;
    placeShips(player1Board);

    cout << "turno del jugador 2: " << endl;
    placeShips(player2Board);

    bool game_Over = false;
    int turn = 1;
    
}