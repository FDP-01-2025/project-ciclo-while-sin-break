#include "pc_vs_player.h"
#include "achievements.h"
#include "board.h"
#include "shot.h"
#include "save_load.h"
#include "music.h" // Music header
#include "language.h"
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

    cout<<getText("name")<<endl;
    cin>>playerName;

    Initializeboard(playerBoard);
    Initializeboard(pcBoard);
    Initializeboard(viewBoardPlayer);
    Initializeboard(viewBoardPc);  

    cout<<playerName<<getText("p_ships")<<endl;
    placeShips(playerBoard);

    cout<<getText("pc_ships")<<endl;
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

        cout<<endl<<currentPlayer<<getText("turn_")<< turn <<")"<<endl;
        displayboard(myView);

        int row, col;
        if (playerTurn){
            string input;
            cout<<getText("coordinates")<<endl;
            cin>>input;

            if (input.length() == 1 && (input[0] == 'Z' || input[0] == 'z')){
                save_Game(playerBoard, pcBoard, viewBoardPlayer, viewBoardPc, playerName, "Computer", turn);
                cout<<getText("g_c")<<endl;
                stopMusic();
                return;
            }

            if (input.length() < 2 || input.length() > 3){
                cout<<getText("input_lng")<<endl;
                continue;
            }

            char rowChar = toupper(input[0]);
            if (rowChar < 'A' || rowChar > 'J'){
                cout<<getText("invalid_r")<<endl;
                continue;
            }
            row = rowChar - 'A';

            try {
                col = stoi(input.substr(1)) - 1;
            }
            catch (...){
                cout<<getText("invalid_c")<<endl;
                continue;
            }

            if(col < 0 || col > 9){
                cout<<getText("col_rang")<<endl;
                continue;
            }

        }

        else{
            do{
                row = rand() % 10;
                col = rand() % 10;
            }
            while(myView[row][col] == 'X' || myView[row][col] == 'O');
    
            cout<<getText("pc_attc")<< char('A' + row) << col + 1 <<endl;  
        }

        bool hit = makeshot(enemyBoard, row, col);
        myView[row][col] = hit ? 'X' : 'O';

        if (hit){
            cout << getText("pc_attc")<< endl;
            (*myConsecutiveHits)++;
        }else {
            cout << getText("miss")<< endl;
            *myConsecutiveHits = 0;
        }

        bool playerWin = hasLost(enemyBoard);
        int shipSize = 0, shipsDestroyed = 0;

        checkAchievements(currentPlayer, hit,*myConsecutiveHits, turn, playerWin, true, shipsDestroyed, shipSize);

        if (playerWin){
            cout<<currentPlayer<< getText("win")<<endl;
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

        std::cout<<endl<<currentPlayer<< getText("turn_")<<turn<<")"<<endl;
        displayboard(myView);

        int row, col;
        std::string input;

        if (playerTurn){
            std::cout<<getText("coordinates")<<endl;
            std::cin>>input;

            if (input == "Z" || input == "z"){
                save_Game(playerBoard, pcBoard, viewBoardPlayer, viewBoardPc, playerName, "Computer",turn);
                std::cout<<getText("g_c")<<endl;
                stopMusic();
                return;
            }

            if (input.length() < 2 || input.length() > 3){
                std::cout<<getText("input_lng")<<endl;
                continue;
            }

            char rowChar = toupper(input[0]);
            if (rowChar < 'A' || rowChar > 'J'){
                std::cout<<getText("invalid_r")<<endl;
                continue;
            }

            try{
                col = std::stoi(input.substr(1)) - 1;
            } catch (...){
                std::cout<<getText("invalid_c")<<endl;
                continue;
            }

            if (col < 0 || col > 9){
                std::cout<<getText("col_rang")<<endl;
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

            std::cout<<getText("pc_attc")<<char('A'+ row) << col + 1<<endl;

        }
        bool hit = makeshot(enemyBoard, row, col);
        myView[row][col] = hit ? 'X' : 'O';

        if (hit){
            std::cout<<getText("hit")<<endl;
            (*myConsecutiveHits)++;
        }
        else {
            std::cout<<getText("miss")<<endl;
            *myConsecutiveHits = 0;
        }

        bool playerWin = hasLost(enemyBoard);
        int shipsDestroyed = 0;
        int shipSize = 0;

        checkAchievements(currentPlayer, hit, *myConsecutiveHits, turn, playerWin, true,shipsDestroyed, shipSize);

        if (playerWin){
            std::cout<<currentPlayer<<getText("win")<<endl;
            stopMusic();
            gameOver = true;
        }
        turn++;
    }
}