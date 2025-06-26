#include "src/board.h"
#include "src/multiplayer.h"
#include <iostream>
using namespace std;

//g++ main.cpp src/board.cpp src/multiplayer.cpp -o juego && juego


int main(){
    char board[10][10];

    Initializeboard(board);
    displayboard(board);
    placeShips(board);
    hasLost(board);

    startMultiplayer();


    return 0;
}