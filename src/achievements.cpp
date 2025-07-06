#include <iostream>
#include "achievements.h"
#include "language.h"

using namespace std;
void checkAchievements(const string &currentPlayer, bool hit, int hit_consecutive, int turn, bool playerwin,
                       bool playerlose, int ships_destroyed, int ship_size)
{
    cout << getText("ach_unlocked")<<endl;

    // Este logro se obtendra cuando un jugador realice 5 aciertos seguidos

    if (hit_consecutive >= 5)
    {
        cout << currentPlayer << getText("sniper")<<endl;
    }

    // Este logro se obtendra cuando un jugador gane sin que le hallan destruido un barco
    if (playerwin && ships_destroyed == 0)
    {
        cout << currentPlayer << getText("undefeated")<<endl;
    }

    // Este logro se obtendra cuando el jugador pierda en menos de 10 turnos
    if (playerlose && turn < 10)
    {
        cout << currentPlayer << getText("disaster")<<endl;
    }

    /*Este logro se obtendra cuando un jugador derribe en el primer disparo
     un barco de tamaño de una casilla*/
    if (hit && ship_size == 1)
    {
        cout << currentPlayer << getText("lucky")<< endl;
    }
}