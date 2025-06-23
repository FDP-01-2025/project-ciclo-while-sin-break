#include <iostream>
#include <fstream>
#include <string>
#include "game_history.h"

using namespace std;

/*Se guarda los tableros y turnos*/
void saveGame(const char board1[10][10], const char board2[10][10], int turn)
{
    ofstream file("game_history.txt");
    if (file.is_open())
    {
        file << turn << '\n';


        if (file.is_open()) {
        file << turn << '\n';

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                file << board1[i][j];
            }
            file << '\n';
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                file << board2[i][j];
            }
            file << '\n';
        }

        file.close();
    }
    else {
        cout << "The game could not be saved." << endl;
    }

}