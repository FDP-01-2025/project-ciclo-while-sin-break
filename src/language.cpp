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
    //{"name1", "Enter player 1 name"},

    //achievements
    {"ach_unlocked", "---Achievements unlocked---"},
    {"sniper", "Sniper: 5 hits in a row"},
    {"undefeated", "Undefeated: to win without losing a single ship"},
    {"disaster", "Total disaster: losing in less than 10 turns"},
    {"lucky", "Lucky Shot: Destroy a ship whith a sigle shot."}
    
};

static std::unordered_map<std::string, std::string> spanish = {
   //main menu
    {"g_options", "opciones de juego"},
    {"pc_player", "1. Juega nueva partida"},
    {"multip", "2. Juega multiplayer"},
    {"load_game", "3. Cargar partida guardada"},
    {"language", "4. Escoja idioma"},
    {"exit", "5. Salir del juego"},

    //board
    {"ship_size", "Colocando barcos de tamanno "},
    {"sym", "(Simbolo '"},
    {"e_starting", "Introduzca las coordenadas de inicio (e.g): "},
    {"direction", "Direccion (H para horizontal, V para vertical: "},
    {"invali_coor", "Coordinadas invalidas. Intente nuevamente"},
    {"invali_dire", "Direccion invalida. Use H o V"},
    {"no_place", "No puede colocar barcos ahí. Intente una nueva posicion "},

    //pc-vs_player
    {"name", "Inrtroduzca su nombre de jugador: "},
    {"p_ships", "Coloque sus barcos"},
    {"pc_ships", "La computadora esta colocando sus barcos..."},
    {"turn_", "'s turno (Turon #"},
    {"coordinates", "Introduzca coordenadas (e.g) o Z para guardar y salir: "},
    {"g_c", "Partida guardada. Regresando al menu..."},
    {"input_lng", "Longitud de entrada no valida. Intenta de nuevo"},
    {"invalid_r", "Fila invalida. Use A-J"},
    {"invalid_c", "Numero de columna invalida"},
    {"col_rang", "Columna fuera de rango. Use numeros 1-10"},
    {"pc_attc", "Computadora ataco a "},
    {"hit", "¡Impacto!"},
    {"miss", "Fallaste..."},
    {"win", "¡GANAS LA PARTIDA!"},

    //multiplayer
    {"name1", "Introduzca el nombre de jugador 1: "},
    {"name2", "Introduzca el nombre de jugador 2: "},
    {"name-ships", ", coloque sus barcos"},
    //{"name1", "Enter player 1 name"},

    //achievements
    {"ach_unlocked", "---Logros desbloqueados---"},
    {"sniper", "Francotirador: 5 golpes en una fila"},
    {"undefeated", "Invicto: por ganar sin perder ni un barco"},
    {"disaster", "Desastre total: perdiendo en menos de 10 turnos"},
    {"lucky", "Golpe de suerte: Destruye un barco con un solo disparo"}
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
