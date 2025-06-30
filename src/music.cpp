#include "music.h"
#include <windows.h>
#include <mmsystem.h>

// Música de menú en loop
void playMenuMusic() {
    PlaySound(TEXT("menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

// Música tranquila de partida en loop
void playCalmMusic() {
    PlaySound(TEXT("calm_game.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

// Música de suspenso en loop
void playSuspenseMusic() {
    PlaySound(TEXT("suspense.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

// Detiene cualquier música que esté sonando
void stopMusic() {
    PlaySound(NULL, 0, 0);
}
