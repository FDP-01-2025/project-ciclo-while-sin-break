#include "pc_vs_player.h"
#include "achievements.h"
#include "board.h"
#include "shot.h"
#include "save_load.h"
#include "music.h" // Music header
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

        string currentPlayer = playerTurn ? playerName : "Computer";
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
        displayboard(myView);

        int row, col;
        if (playerTurn){
            string input;
            cout<<"Enter coordinates (e.g. G5) or Z to save and exit: ";
            cin>>input;

            if (input.length() == 1 && (input[0] == 'Z' || input[0] == 'z')){
                save_Game(playerBoard, pcBoard, viewBoardPlayer, viewBoardPc, playerName, "Computer", turn);
                cout<<"Game saved. Returning to menu"<<endl;
                stopMusic();
                return;
            }

            if (input.length() < 2 || input.length() > 3){
                cout<<"Invalid input length. Please try again"<<endl;
                continue;
            }

            char rowChar = toupper(input[0]);
            if (rowChar < 'A' || rowChar > 'J'){
                cout<<"Invalid row. Please try again"<<endl;
                continue;
            }
            row = rowChar - 'A';

            try {
                col = stoi(input.substr(1)) - 1;
            }
            catch (...){
                cout<<"Innvalid column number."<<endl;
                continue;
            }

            if(col < 0 || col > 9){
                cout<<"Column out of range. Use numbers 1-10"<<endl;
                continue;
            }

        }

        else{
            do{
                row = rand() % 10;
                col = rand() % 10;
            }
            while(myView[row][col] == 'X' || myView[row][col] == 'O');
    
            cout<<"Computer attacks at "<< char('A' + row) << col + 1 <<endl;  
        }

        bool hit = makeshot(enemyBoard, row, col);
        myView[row][col] = hit ? 'X' : 'O';

        if (hit){
            cout << "Hit!" << endl;
            (*myConsecutiveHits)++;
        }else {
            cout << "Miss..." << endl;
            *myConsecutiveHits = 0;
        }

        bool playerWin = hasLost(enemyBoard);
        int shipSize = 0, shipsDestroyed = 0;

        checkAchievements(currentPlayer, hit,*myConsecutiveHits, turn, playerWin, true, shipsDestroyed, shipSize);

        if (playerWin){
            cout<<currentPlayer<< " WINS THE GAME!"<<endl;
            stopMusic();
            gameOver = true;
        }
        turn++;
    }


}

void  ContinuePcVsPlayer(char playerBoard[10][10], char pcBoard[10][10],
                        char viewBoardPlayer[10][10], char viewBoardPc[10][10],
                        string playerName, int turn){
    bool gameOver = false;
    int hitConsecutivePlayer = 0, hitConsecutivePc = 0;

    playCalmMusic();

    while(!gameOver){
        bool playerTurn = (turn % 2 != 0);
        std::string currentPlayer = playerTurn ? playerName : "Computer";

        char  (*myBoard)[10] = playerTurn ? playerBoard : pcBoard;
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

        if (shipsLeft == 1) playSuspenseMusic();

        std::cout<<endl<<currentPlayer<< "'s turn (Turn #"<<turn<<")"<<endl;
        displayboard(myView);

        int row, col;
        std::string input;

        if (playerTurn){
            std::cout<<"Enter coordinates (e.g. B7) or Z to save and exit: ";
            std::cin>>input;

            if (input == "Z" || input == "z"){
                save_Game(playerBoard, pcBoard, viewBoardPlayer, viewBoardPc, playerName, "Computer",turn);
                std::cout<<"Game saved. Returing to menu"<<endl;
                stopMusic();
                return;
            }

            if (input.length() < 2 || input.length() > 3){
                std::cout<<"Invalid input length. Please try again."<<endl;
                continue;
            }

            char rowChar = toupper(input[0]);
            if (rowChar < 'A' || rowChar > 'J'){
                std::cout<<"Invalid row. Use A-J"<<endl;
                continue;
            }

            try{
                col = std::stoi(input.substr(1)) - 1;
            } catch (...){
                std::cout<<"Invalid column number"<<endl;
                continue;
            }

            if (col < 0 || col > 9){
                std::cout<<"Column out of range. Use 1-10"<<endl;
                continue;
            }
        }
        else{
            row = rand() % 10;
            col = rand() % 10;

            while(myView[row][col] == 'X' || myView[row][col] == 'O'){
                row = rand() % 10;
                col = rand() % 10;
            }

            std::cout<<"Computer shoots at "<<char('A'+ row) << col + 1<<endl;

        }
        bool hit = makeshot(enemyBoard, row, col);
        myView[row][col] = hit ? 'X' : 'O';

        if (hit){
            std::cout<<"Hit!"<<endl;
            (*myConsecutiveHits)++;
        }
        else {
            std::cout<<"Miss..."<<endl;
            *myConsecutiveHits = 0;
        }

        bool playerWin = hasLost(enemyBoard);
        int shipsDestroyed = 0;
        int shipSize = 0;

        checkAchievements(currentPlayer, hit, *myConsecutiveHits, turn, playerWin, true,shipsDestroyed, shipSize);

        if (playerWin){
            std::cout<<currentPlayer<<" WIN THE GAME!"<<endl;
            stopMusic();
            gameOver = true;
        }
        turn++;
    }
}