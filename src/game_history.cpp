#include <iostream>
#include <fstream>
#include <string>
#include "game_history.h"

using namespace std;

/*Se realiza el guardado de los tableros, turnos y se verifica si
la partida a finalizado o sigue en proceso y en dado caso siguiese en proceso
podra reanudarla*/
void saveGame(const char board1[10][10], const char board2[10][10], int turn, bool finished) {
    ofstream history("game_history.txt", ios::app);

    if (history.is_open()) {
        history << turn << '\n';

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                history << board1[i][j];
            }
            history << '\n';
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                history << board2[i][j];
            }
            history << '\n';
        }

        history << (finished ? "finished" : "in_progress") << '\n';
        history.close();
    }

    if (!finished) {
        ofstream file("current_game.txt");

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

            file << "in_progress" << '\n';
            file.close();
        }
    } else {
        remove("current_game.txt");
    }
}

/*Inteta acceder al archivo guardado para luego cargar los datos
almacenados y en dado caso el archivo este guardado*/
bool loadGame(char board1[10][10], char board2[10][10], int &turn) {
    ifstream file("current_game.txt");

    if (file.is_open()) {
        file >> turn;
        file.ignore();

        string line;
        for (int i = 0; i < 10; i++) {
            getline(file, line);
            for (int j = 0; j < 10; j++) {
                board1[i][j] = line[j];
            }
        }

        for (int i = 0; i < 10; i++) {
            getline(file, line);
            for (int j = 0; j < 10; j++) {
                board2[i][j] = line[j];
            }
        }

        string status;
        getline(file, status);
        file.close();

        if (status == "in_progress") {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
