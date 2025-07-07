#include <iostream>
#include "achievements.h"
#include "language.h"

using namespace std;

void checkAchievements(const string &currentPlayer, bool hit, int hit_consecutive, int turn, 
                       bool playerwin, bool playerlose, int ships_destroyed, int ship_size)
{
    bool anyUnlocked = false;

    if (hit_consecutive >= 5) {
        cout << currentPlayer << getText("sniper") << endl;
        anyUnlocked = true;
    }

    if (playerwin && ships_destroyed == 0) {
        cout << currentPlayer << getText("undefeated") << endl;
        anyUnlocked = true;
    }

    // Logro si la computadora pierde en menos de 10 turnos
    if (playerwin && currentPlayer != "Computer" && turn < 10) {
        cout << getText("computer_disaster") << endl;
        anyUnlocked = true;
    }

    if (anyUnlocked) {
        cout << getText("ach_unlocked") << endl;
    }
}
