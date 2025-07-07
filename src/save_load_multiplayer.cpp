#include "save_load_multiplayer.h"
#include <iostream>
#include <fstream>
using namespace std;

void saveMultiplayerGame(char board1[10][10], char board2[10][10], 
                         char view1[10][10], char view2[10][10],
                         const string &name1, const string &name2, int turn)
{
    ofstream file("multiplayer_save.txt");

    if (!file.is_open()) {
        cout << "Error saving multiplayer game." << endl;
        return;
    }

    file << name1 << " " << name2 << " " << turn << endl;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            file << board1[i][j];
    
    file << endl;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            file << board2[i][j];
    
    file << endl;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            file << view1[i][j];
    
    file << endl;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            file << view2[i][j];

    file << endl;
    file.close();

    cout << "Multiplayer game saved successfully." << endl;
}

bool loadMultiplayerGame(char board1[10][10], char board2[10][10], 
                         char view1[10][10], char view2[10][10],
                         string &name1, string &name2, int &turn)
{
    ifstream file("multiplayer_save.txt");

    if (!file.is_open()) {
        cout << "No multiplayer saved game found." << endl;
        return false;
    }

    file >> name1 >> name2 >> turn;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            file >> board1[i][j];

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            file >> board2[i][j];

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            file >> view1[i][j];

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            file >> view2[i][j];

    file.close();
    cout << "Multiplayer game loaded successfully." << endl;
    return true;
}