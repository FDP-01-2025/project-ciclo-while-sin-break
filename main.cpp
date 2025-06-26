#include "src/board.h"
#include "src/multiplayer.h"
#include <iostream>
using namespace std;

//g++ main.cpp src/board.cpp src/multiplayer.cpp -o juego && juego


int main(){
    int options;
    char board[10][10];

    Initializeboard(board);
    displayboard(board);
    placeShips(board);
    hasLost(board);

    startMultiplayer();

    cout <<"Las opciones de juego:" << endl;
    cout << "1. Jugar" <<endl;
    cout << "2. Multijugador" <<endl;
    cout << "3. Historial de partida" <<endl;
    cout << "4. Logros" <<endl;
    cin >> options;

    
    


    return 0;
}