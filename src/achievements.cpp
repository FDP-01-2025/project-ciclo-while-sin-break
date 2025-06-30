#include <iostream>
#include "achievements.h"

using namespace std;

void checkAchievements(const string &currentPlayer, bool hit, int hit_consecutive, int turn, bool playerwin, bool playerlose, int ships_destroye)
{
    cout << "\n--- Achievements unlocked ---\n";

    /*Este logro se mostrara cuando un jugador realice 5 aciertos seguidos
     */
    if (hit_consecutive >= 5)
    {
        cout << currentPlayer << "Sniper: 5 hits in a row.\n";
    }
    if (playerwin && ships_destroye == 0)
    {
        cout << currentPlayer << "“Undefeated”: to win without losing a single ship.\n";
    }
}