#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H
#include <iostream>
using namespace std;

void checkAchievements(const string &currentPlayer, bool hit, int hit_consecutive, int turn,
                       bool playerwin, bool playerlose, int ships_destroyed, int ship_size);
/*
Se utiliza para verificar si se desbloquean logros durante la partida.
 playerName: nombre del jugador actual
 hit: true si el último disparo fue un acierto
 hit_consecutive: cantidad de aciertos consecutivos
 turn: numero de turno actual
 playerwin: true si el jugador gano
 playerlose: true si el jugador perdio.
 shipsDestroyed: cantidad de barcos destruidos por el jugador
 ship_size: tamaño del barco destruido
*/
#endif
