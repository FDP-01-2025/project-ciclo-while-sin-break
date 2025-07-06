#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <string>



enum Language {
    ENGLISH,
    SPANISH
};

extern Language currentLanguage;

std::string getText(const std::string& key);
void setLanguage(Language lang);

#endif // LANGUAGE_H    