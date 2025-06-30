#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H
#include <iostream>
using namespace std;

void checkAchievements(const string& currentPlayer ,bool hit, int hit_consecutive, int turn, bool playerwin, bool playerlose,
                       int ships_destroye); /*Se utilizaran estas variables para poder asignar los
                       siguientes logros (se han especificado en el documento):
                       ● “Francotirador”: 5 aciertos seguidos.
                       ● “Invicto”: ganar sin perder un solo barco.
                       ● “Desastre total”: perder en menos de 10 turnos.*/
#endif 
