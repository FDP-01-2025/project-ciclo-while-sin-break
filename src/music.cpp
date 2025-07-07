#include "music.h"
#include <windows.h>
#include <mmsystem.h>

// Reproduce la música del menú en loop
void playMenuMusic() {
    PlaySound(TEXT("src/menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

// Reproduce música tranquila durante la partida
void playCalmMusic() {
    PlaySound(TEXT("src/calm_game.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

// Reproduce música de suspenso cuando queda un solo barco
void playSuspenseMusic() {
    PlaySound(TEXT("src/suspense.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

// Detiene cualquier música que esté sonando
void stopMusic() {
    PlaySound(NULL, 0, 0);
}
