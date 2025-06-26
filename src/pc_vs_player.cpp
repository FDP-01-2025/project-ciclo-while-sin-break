#include "pc_vs_player.h";
#include "achievements.h";
#include "board.h";
#include "shot.h";
#include <iostream>
#include <cstdlib> //Esta funcion ayuda a elegir random la posicion de los barcos
#include <ctime>
using namespace std;

void playerVsPC(){

    playCalmMusic();

    char playerBoard[10][10], pcBoard[10][10];
    char viewBoardPlayer[10][10], viewBoardPc[10][10];
    string playerName;
    int turn = 1;
    int hitConsecutivePlayer = 0, hitConsecutivePc = 0;

    cout<<"Enter your player name: ";
    cin>>playerName;

    Initializeboard(playerBoard);
    Initializeboard(pcBoard);
    Initializeboard(viewBoardPlayer);
    Initializeboard(viewBoardPc);  

    cout<<playerName<<", place your ships"<<endl;
    placeShips(playerBoard);

    cout<<"Pc is placing ships"<<endl;
    placeShipRandom(pcBoard);

    bool gameOver = false;

    while(!gameOver){
        bool playerTurn = (turn % 2 != 0);

        string currentPlayer = playerTurn ? playerName : "Computer1";
        char (*myBoard)[10] = playerTurn ? playerBoard : pcBoard;
        char (*enemyBoard)[10] = playerTurn ? pcBoard : playerBoard;
        char (*myView)[10] = playerTurn ? viewBoardPlayer : viewBoardPc;
        int *myConsecutiveHits = playerTurn ? &hitConsecutivePlayer : &hitConsecutivePc;

        int shipsLeft = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (enemyBoard[i][j] == 'B')
                shipsLeft++;
            }
        }

        if (shipsLeft == 1){
            playSuspenseMusic();
        }

        cout<<endl<<currentPlayer<<"'s turn (Turn #"<< turn <<")"<<endl;
        displayboard(myView)
    }


}