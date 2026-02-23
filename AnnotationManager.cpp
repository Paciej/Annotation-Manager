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

AnnotationManager::AnnotationManager(int numOfArguments, char *arguments[]) {
    parseRawInformation(numOfArguments, arguments);    
}

void AnnotationManager::getParametersFromUser()
{
    bool paramGood = false;

    std::string newParam;

    while (!paramGood) {
        std::cout << "podaj styl adnotacji (sl dla wyswietlenia listy): ";
        std::getline(std::cin, newParam);
        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (newParam == "sl") {
            // WYSWIETL LISTE DOSTEPNYCH STYLI
            std::cout << std::endl << "Lista styli" << std::endl;
            for (auto style : styleMap) {
                std::cout << style.first << std::endl;
            }
            continue;
        } else {
            for (auto style : styleMap) {
                if (newParam == style.first) {
                    this->annStyle = style.second;
                    std::cout << "Poprawnie wybrano styl" << std::endl;
                    paramGood = true;
                    break;
                }
            }

            if (this->annStyle == AnnotationStyle::None) {
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
                    this->annCat = category.second;
                    std::cout << "Poprawnie wybrano kategorie" << std::endl;
                    paramGood = true;
                    break;
                }
            }

            if (this->annCat == AnnotationCategory::None) {
                std::cout << "Niestety, taka kategoria: " << newParam <<  " nie jest oblugiwana lub nie istnieje. Pamietaj, ze kategoria jest case sensitive" << std::endl;
            }
        }
    }
    setSingleParamFromUser(this->author, "Autor", 1);
    setSingleParamFromUser(this->title, "tytul", 1);
    setSingleParamFromUser(this->year, "rok", 0);
    setSingleParamFromUser(this->pages, "strony", 0);
    
}

void AnnotationManager::listParameters()
{
    std::cout << std::endl << "Wprowadzone dane: " << std::endl;
    std::cout << "Styl: " << styleToString(this->annStyle) << std::endl;
    std::cout << "Kategoria: " << categoryToString(this->annCat) << std::endl;
    std::cout << "Autor: " << this->author << std::endl;
    std::cout << "Dzielo: " << this->title << std::endl;
    std::cout << "Rok: " << this->year << std::endl;
    std::cout << "Strony: " << this->pages << std::endl;
}

void AnnotationManager::parseRawInformation(int argCount, char *args[]) {
    
}