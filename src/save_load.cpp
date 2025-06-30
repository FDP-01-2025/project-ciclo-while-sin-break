#include "save_load.h"
#include <fstream>
#include <iostream>
using namespace std;

const string SAVE_HEADER = "BATTLESHIP_SAVE_V1";

// Guardar partida con cabecera
void save_Game(const char board1[10][10], const char board2[10][10],
              const char view1[10][10], const char view2[10][10],
              const string& name1, const string& name2, int turn) 
{
    ofstream file("saved_game.txt"); // Creamos o sobreescribimos el archivo
    if (file.is_open()) 
    {
        // Escribir cabecera
        file << SAVE_HEADER << endl;

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

// Cargar partida con validación de cabecera
void load_Game(char board1[10][10], char board2[10][10],
              char view1[10][10], char view2[10][10],
              string& name1, string& name2, int& turn) 
{
    ifstream file("saved_game.txt"); // Abrimos el archivo de guardado
    if (file.is_open()) 
    {
        // Leer y validar cabecera
        string header;
        getline(file, header);
        if (header != SAVE_HEADER) {
            cout << "Error: Save file corrupted or incompatible." << endl;
            file.close();
            return;
        }

        // Leemos los nombres y el turno
        getline(file, name1);
        getline(file, name2);
        file >> turn;
        file.ignore(); 

        //ler tablero de cada jugador
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
