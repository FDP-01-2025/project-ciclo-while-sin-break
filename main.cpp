#include "src/board.h"
#include "src/multiplayer.h"
#include "src/save_load.h"  // Para partidas contra PC
#include "src/save_load_multiplayer.h"  // Para partidas multijugador
#include "src/music.h"
#include "src/pc_vs_player.h"
#include "src/language.h"
#include <iostream>
using namespace std;

// Prototipos
void continueMultiplayer(char board1[10][10], char board2[10][10],
                        char view1[10][10], char view2[10][10],
                        string name1, string name2, int turn);

void ContinuePcVsPlayer(char playerBoard[10][10], char pcBoard[10][10],
                       char viewBoardPlayer[10][10], char viewBoardPc[10][10],
                       string playerName, int turn);

int main() {
    int options;
    bool exitGame = false;

    playMenuMusic();

    while (!exitGame)
    {
        cout << getText("g_options") << endl;
        cout << getText("pc_player") << endl;
        cout << getText("multip") << endl;
        cout << getText("load_game") << endl;
        cout << getText("language") << endl;
        cout << getText("exit") << endl;
        cout << getText("ch_op") << endl;
        cin >> options;

        switch (options) {
            case 1: {
                playCalmMusic();
                playerVsPC();
                playMenuMusic();
                break;
            }

            case 2: {
                stopMusic();
                startMultiplayer();
                playMenuMusic();
                break;
            }

            case 3: {
                stopMusic();
                int modeChoice;
                
                cout << "1. Load PC vs Player Game" << endl;
                cout << "2. Load Multiplayer Game" << endl;
                cin >> modeChoice;

                char board1[10][10], board2[10][10];
                char view1[10][10], view2[10][10];
                string name1, name2;
                int turn;

                if (modeChoice == 1) {
                    load_Game(board1, board2, view1, view2, name1, name2, turn);
                    cout << getText("load_G") << name1 << getText("and") << name2 << "." << endl;
                    ContinuePcVsPlayer(board1, board2, view1, view2, name1, turn);
                } else if (modeChoice == 2) {
                    loadMultiplayerGame(board1, board2, view1, view2, name1, name2, turn);
                    cout << getText("load_G") << name1 << getText("and") << name2 << "." << endl;
                    continueMultiplayer(board1, board2, view1, view2, name1, name2, turn);
                } else {
                    cout << getText("inv_op") << endl;
                }

                playMenuMusic();
                break;
            }

            case 4: {
                playCalmMusic();
                int langChoice;
                cout << "1. English" << endl;
                cout << "2. Spanish" << endl;
                cout << "Choose a language" << endl;
                cin >> langChoice;

                if (langChoice == 2) {
                    setLanguage(SPANISH);
                } else {
                    setLanguage(ENGLISH);
                }
                playMenuMusic();
                break;
            }

            case 5:
                cout << getText("leav_g") << endl;
                exitGame = true;
                break;

            default:
                cout << getText("inv_op") << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                break;
        }
    }

    stopMusic();
    return 0;
}