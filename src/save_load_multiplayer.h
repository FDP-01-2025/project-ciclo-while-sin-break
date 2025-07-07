#ifndef SAVE_LOAD_MULTIPLAYER_H
#define SAVE_LOAD_MULTIPLAYER_H

#include <string>

// Función para guardar partida multijugador
void saveMultiplayerGame(char board1[10][10], char board2[10][10], 
                         char view1[10][10], char view2[10][10],
                         const std::string &name1, const std::string &name2, int turn);

// Función para cargar partida multijugador
bool loadMultiplayerGame(char board1[10][10], char board2[10][10], 
                         char view1[10][10], char view2[10][10],
                         std::string &name1, std::string &name2, int &turn);

#endif