#include "language.h"
#include <unordered_map>

static Language currentLanguage = ENGLISH;

static std::unordered_map<std::string, std::string> english = {
    //main menu
    {"g_options", "Game options"},
    {"pc_player", "1. Play new game"},
    {"multip", "2. Play multiplayer"},
    {"load_game", "3. Load game saved"},
    {"language", "4. Choose language"},
    {"exit", "5. Exit game"},

    //board
    {"ship_size", "Placing ships of size "},
    {"sym", "(Symbol '"},
    {"e_starting", "Enter starting coordinates (e.g): "},
    {"direction", "Direction (H for horizontal, V for vertical): "},
    {"invali_coor", "Invalid coordinates. Try again"},
    {"invali_dire", "Invalid direction. Use H or V"},
    {"no_place", "Cannot place the ship there. Try a different position"},

    //pc-vs_player
    {"name", "Enter your player name"},
    {"p_ships", "Place your ships"},
    {"pc_ships", "Pc is placing ships..."},
    {"turn_", "'s turn (Turn #"},
    {"coordinates", "Enter coordinates (e.g) or Z to save and exit: "},
    {"g_c", "Game saved. Returning to menu"},
    {"input_lng", "Invalid input length. Please try again"},
    {"invalid_r", "Invalid row. Use A-J"},
    {"invalid_c", "Invalid column number"},
    {"col_rang", "Column out of range. Use number 1-10"},
    {"pc_attc", "Computer attacks at "},
    {"hit", "Hit!"},
    {"miss", "Miss..."},
    {"win", "WINS THE GAME!"},

    //multiplayer
    {"name1", "Enter player 1 name: "},
    {"name2", "Enter player 2 name: "},
    {"name-ships", ", place your ships"},
    {"name1", "Enter player 1 name"},

    //achievements
    {"ach_unlocked", "---Achievements unlocked---"},
    {"sniper", "Sniper: 5 hits in a row"},
    {"undefeaded", "Undefeated: to win without losing a single ship"},
    {"disaster", "Total disaster: losing in less than 10 turns"},
    {"lucky", "Lucky Shot: Destroy a ship whith a sigle shot."},
    
};

static std::unordered_map<std::string, std::string> spanish = {
    {"welcome", "Bienvenido a Battleship"},
    {"enter_name", "Ingresa tu nombre de jugador: "},
    {"place_ships", "Coloca tus barcos"},
    {"turn", "Turno"},
    {"hit", "¡Impacto!"},
    {"miss", "Fallaste..."},
    {"win", "¡gana el juego!"},
    {"enter_coords", "Ingresa coordenadas (por ej. G5) o Z para guardar y salir: "}
};

void setLanguage(Language lang) {
    currentLanguage = lang;
}

std::string getText(const std::string& key) {
    if (currentLanguage == SPANISH) {
        return spanish[key];
    }
    return english[key];
}
