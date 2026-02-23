#include "AnnotationManager.h"
#include <iostream>

template <typename T>
void AnnotationManager::setSingleParamFromUser(T& param, const char* name, bool askIfGood) {
    bool newParamSet = false;

    while (!newParamSet) {
        std::cout << "Podaj wartosc dla " << name << ": " << std::endl;
        std::string newParam;
        std::getline(std::cin, newParam);

        if (askIfGood) {
            bool answerGood = false;
            while (!answerGood) {
                std::cout << "Czy " << name << " ma byc " << newParam << "? [T/n]: ";
                char answer;
                std::cin >> answer;
                std::cin.get();
                
                switch (answer) {
                    case 'T':
                    case 't': param = newParam; newParamSet = true; answerGood = true; break;
                    case 'N':
                    case 'n': std::cout << std::endl << "Odrzucono podana wartosc" << std::endl; answerGood = true; break;
                    default: std::cout << std::endl << "Podaj wartosc jeszcze raz" << std::endl; 
                }
            }
        } else {
            param = newParam;
            newParamSet = true;        
        }
    }
}

AnnotationManager::AnnotationManager(){}

AnnotationManager::AnnotationManager(int numOfArguments, char *arguments[])
{
    parseRawInformation(numOfArguments, arguments);
}

AnnotationData AnnotationManager::getAnnotationVariablesStruct()
{
    return this->annData;
}

void AnnotationManager::getParametersFromUser()
{
    bool paramGood = false;

    std::string newParam;

    while (!paramGood) {
        std::cout << "podaj styl adnotacji (ls dla wyswietlenia listy): ";
        std::getline(std::cin, newParam);

        if (newParam == "ls") {
            // WYSWIETL LISTE DOSTEPNYCH STYLI
            std::cout << std::endl << "Lista styli" << std::endl;
            for (auto style : styleMap) {
                std::cout << style.first << std::endl;
            }
            continue;
        } else {
            for (auto style : styleMap) {
                if (newParam == style.first) {
                    this->annData.annStyle = style.second;
                    std::cout << "Poprawnie wybrano styl" << std::endl;
                    paramGood = true;
                    break;
                }
            }

            if (this->annData.annStyle == AnnotationStyle::None) {
                std::cout << "Niestety, taki styl nie jest oblugiwany lub nie istnieje. Pamietaj, ze styl jest case sensitive" << std::endl;
            }
            continue;
        }
    }

    paramGood = false;
    while (!paramGood) {
        std::cout << "podaj kategorie adnotacji (cl dla wyswietlenia listy): ";
        std::getline(std::cin, newParam);

        if (newParam == "cl") {
            // WYSWIETL LISTE DOSTEPNYCH KATEGORII
            std::cout << std::endl << "Lista kategorii" << std::endl;
            for (auto category : catMap) {
                std::cout << category.first << std::endl;
            }

        } else {
            for (auto category : catMap) {
                if (newParam == category.first) {
                    this->annData.annCat = category.second;
                    std::cout << "Poprawnie wybrano kategorie" << std::endl;
                    paramGood = true;
                    break;
                }
            }

            if (this->annData.annCat == AnnotationCategory::None) {
                std::cout << "Niestety, taka kategoria: " << newParam <<  " nie jest oblugiwana lub nie istnieje. Pamietaj, ze kategoria jest case sensitive" << std::endl;
            }
        }
    }
    setSingleParamFromUser(this->annData.author, "Autor", 0);
    setSingleParamFromUser(this->annData.title, "tytul", 0);
    setSingleParamFromUser(this->annData.year, "rok", 0);
    setSingleParamFromUser(this->annData.pages, "strony", 0);
    setSingleParamFromUser(this->annData.place, "Miejsce", 0);    
    setSingleParamFromUser(this->annData.publisher, "Wydawca", 0);    
    setSingleParamFromUser(this->annData.url, "Url", 0);    
}

void AnnotationManager::listParameters()
{
    std::cout << std::endl << "Wprowadzone dane: " << std::endl;
    std::cout << "Styl: " << styleToString(this->annData.annStyle) << std::endl;
    std::cout << "Kategoria: " << categoryToString(this->annData.annCat) << std::endl;
    std::cout << "Autor: " << this->annData.author << std::endl;
    std::cout << "Dzielo: " << this->annData.title << std::endl;
    std::cout << "Rok: " << this->annData.year << std::endl;
    std::cout << "Strony: " << this->annData.pages << std::endl;
}

void AnnotationManager::parseRawInformation(int argCount, char *args[]) {
    
}