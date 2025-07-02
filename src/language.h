#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <string>

enum Language {ENGLISH, SPANISH};

void setLanguage(Language lang);
std::string getText(const std::string& key);



#endif