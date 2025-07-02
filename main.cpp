#include "src/board.h"
#include "src/multiplayer.h"
#include "src/save_load.h"
#include "src/music.h" // Music header
#include "src/pc_vs_player.h"
#include <iostream>
using namespace std;

void continueMultiplayer(char board1[10][10], char board2[10][10],
                        char view1[10][10], char view2[10][10],
                        string name1, string name2, int turn);

void ContinuePcVsPlayer(char playerBoard[10][10], char pcBoard[10][10],
                        char viewBoardPlayer[10][10], char viewBoardPc[10][10],
                        string playerName, int turn);

int main() {
    int options;
    bool exitGame = false;

    playMenuMusic(); // Play menu music

    while (!exitGame)
    {
        cout << "\nGame options" << endl;
        cout << "1. Play new game" << endl;
        cout << "2. New Multiplayer game" << endl;
        cout << "3. Load Saved Game" << endl;
        cout << "4. Exit the game" << endl;
        cout << "Choose an option: ";
        cin >> options;

        switch (options) {
            case 1:{
                playCalmMusic();
                //char playerBoard[10][10], pcBoard[10][10];
                //har viewBoardPlayer[10][10], viewBoardPc[10][10];
                playerVsPC();
                //ContinuePcVsPlayer()
                break;
            }

            case 2: {
                stopMusic();
                startMultiplayer();
                playMenuMusic();
                break;
                
            }

            case 3:{
                stopMusic();
                char board1[10][10], board2[10][10];
                char view1[10][10], view2[10][10];
                string name1, name2;
                int turn;

                load_Game(board1, board2, view1, view2, name1, name2, turn);
                cout << "\nLoaded game for " << name1 << " and " << name2 << "." << endl;
                
                if (name2 == "Computer") {
                    ContinuePcVsPlayer(board1, board2, view1, view2, name1, turn);
                } else {
                    continueMultiplayer(board1, board2, view1, view2, name1, name2, turn);
                }
                
                break;
            }

            case 4:
                cout << "Leaving the game" << endl;
                exitGame = true;
                break;

            default:
                cout << "Invalid option, try again." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                break;
        }
    }

    stopMusic();
    return 0;
}
