#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include <string>
using namespace std;

// Guarda toda la partida en un archivo
void saveGame(const char board1[10][10], const char board2[10][10],
              const char view1[10][10], const char view2[10][10],
              const string& name1, const string& name2, int turn);

// Carga la partida desde el archivo
void load_Game(char board1[10][10], char board2[10][10],
              char view1[10][10], char view2[10][10],
              string& name1, string& name2, int& turn);

#endif
