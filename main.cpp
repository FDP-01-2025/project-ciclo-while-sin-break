#include "src/board.h"
#include "src/multiplayer.h"
#include <iostream>
using namespace std;

// g++ main.cpp src/board.cpp src/multiplayer.cpp -o juego && juego

int main() {
    int options;
    bool exitGame = false;
while (!exitGame)
{
    


    cout << "Game options" << endl;
    cout << "1. New Multiplayer game" << endl;
    cout << "2. Load Saved Game" << endl;
    cout << "3. Exit the game" << endl;
    cin >> options;

    switch (options) {
    case 1:
        startMultiplayer();
        break;

    case 2: {
        char board1[10][10], board2[10][10];
        char view1[10][10], view2[10][10];
        string name1, name2;
        int turn;

        load_Game(board1, board2, view1, view2, name1, name2, turn);
        cout << "\nLoaded game for " << name1 << " and " << name2 << "." << endl;
        continueMultiplayer(board1, board2, view1, view2, name1, name2, turn);
        break;
        }

        case 3:
        cout << "Leaving the game" << endl;
        break;

        default:
            cout << "Invalid option, try again." << endl;
            break;

        }
        }
            return 0;
    }