#include <iostream>
#include "achievements.h"

using namespace std;
void checkAchievements(const string &currentPlayer, bool hit, int hit_consecutive, int turn, bool playerwin,
                       bool playerlose, int ships_destroyed, int ship_size)
{
    cout << "\n--- Achievements unlocked ---\n";

    // Este logro se obtendra cuando un jugador realice 5 aciertos seguidos

    if (hit_consecutive >= 5)
    {
        cout << currentPlayer << " “Sniper”: 5 hits in a row.\n";
    }

    // Este logro se obtendra cuando un jugador gane sin que le hallan destruido un barco
    if (playerwin && ships_destroyed == 0)
    {
        cout << currentPlayer << " “Undefeated”: to win without losing a single ship.\n";
    }

    // Este logro se obtendra cuando el jugador pierda en menos de 10 turnos
    if (playerlose && turn < 10)
    {
        cout << currentPlayer << " “Total disaster”: losing in less than 10 turns.\n";
    }

    /*Este logro se obtendra cuando un jugador derribe en el primer disparo
     un barco de tamaño de una casilla*/
    if (hit && ship_size == 1)
    {
        cout << currentPlayer << " “Lucky Shot”: Destroy a ship with a single shot." << endl;
    }
}