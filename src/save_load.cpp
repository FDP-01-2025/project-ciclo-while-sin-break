#include "save_load.h"
#include <fstream>
#include <iostream>
using namespace std;

// Esta función guarda todo el estado de la partida en un archivo txt
void save_Game(const char board1[10][10], const char board2[10][10],
              const char view1[10][10], const char view2[10][10],
              const string& name1, const string& name2, int turn) 
{
    ofstream file("saved_game.txt"); // Creamos o sobreescribimos el archivo
    if (file.is_open()) 
    {
        // Primero guardamos los nombres de los jugadores y el turno
        file << name1 << endl;
        file << name2 << endl;
        file << turn << endl;

        // Luego guardamos el tablero de cada jugador
        for (int i = 0; i < 10; i++) 
        {
            for (int j = 0; j < 10; j++) 
            {
                file << board1[i][j];
            }
            file << endl;
        }

        for (int i = 0; i < 10; i++) 
        {
            for (int j = 0; j < 10; j++) 
            {
                file << board2[i][j];
            }
            file << endl;
        }

        // Después guardamos lo que cada jugador ve del tablero enemigo
        for (int i = 0; i < 10; i++) 
        {
            for (int j = 0; j < 10; j++) 
            {
                file << view1[i][j];
            }
            file << endl;
        }

        for (int i = 0; i < 10; i++) 
        {
            for (int j = 0; j < 10; j++) 
            {
                file << view2[i][j];
            }
            file << endl;
        }

        file.close();
        cout << "Game saved successfully :)" << endl;
    }
    else 
    {
        cout << "Error: could not save the game :(" << endl;
    }
}

// Esta función carga los datos guardados de la partida y los mete al juego
void load_Game(char board1[10][10], char board2[10][10],
              char view1[10][10], char view2[10][10],
              string& name1, string& name2, int& turn) 
{
    ifstream file("saved_game.txt"); // Abrimos el archivo de guardado
    if (file.is_open()) 
    {
        // Leemos los nombres y el turno
        getline(file, name1);
        getline(file, name2);
        file >> turn;
        file.ignore(); // Saltamos el enter después del turno

        // Leemos los tableros de cada jugador
        for (int i = 0; i < 10; i++) 
        {
            string line;
            getline(file, line);
            for (int j = 0; j < 10; j++) 
            {
                board1[i][j] = line[j];
            }
        }

        for (int i = 0; i < 10; i++) 
        {
            string line;
            getline(file, line);
            for (int j = 0; j < 10; j++) 
            {
                board2[i][j] = line[j];
            }
        }

        // Leemos lo que cada jugador ve del tablero enemigo
        for (int i = 0; i < 10; i++) 
        {
            string line;
            getline(file, line);
            for (int j = 0; j < 10; j++) 
            {
                view1[i][j] = line[j];
            }
        }

        for (int i = 0; i < 10; i++) 
        {
            string line;
            getline(file, line);
            for (int j = 0; j < 10; j++) 
            {
                view2[i][j] = line[j];
            }
        }

        file.close();
        cout << "Game loaded successfully! Ready to continue." << endl;
    }
    else 
    {
        cout << "No saved game found :(" << endl;
    }
}
