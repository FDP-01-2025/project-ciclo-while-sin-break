#include <iostream>
#include "achievements.h"

using namespace std;
void checkAchievements(const string& currentPlayer, bool hit, int hit_consecutive, int turn, bool playerwin, bool playerlose, int ships_destroyed)
{
    cout << "\n--- Achievements unlocked ---\n";

    if (hit_consecutive >= 5)
    {
        cout << currentPlayer << " Sniper: 5 hits in a row.\n";
    }
    if (playerwin && ships_destroyed == 0)
    {
        cout << currentPlayer << "“ Undefeated”: to win without losing a single ship.\n";
    }
    if (playerlose && turn < 10)
    {
        cout << currentPlayer << "“ Total disaster”: losing in less than 10 turns.\n";
    }
}