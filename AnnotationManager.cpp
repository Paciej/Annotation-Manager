#include "AnnotationManager.h"
#include <limits>

template <typename T>
void AnnotationManager::setSingleParamFromUser(T& param, const char* name, bool askIfGood) {
    bool newParamSet = false;

    while (!newParamSet) {
        std::cout << "set " << name << ": " << std::endl;
        T newParam;
        std::cin >> newParam;

        if (askIfGood) {
            std::cout << "Czy " << name << " ma byc " << newParam << "? [T/n]: ";
            char answer;
            std::cin >> answer;
            
            switch (answer) {
                case 'T':
                case 't': param = newParam; newParamSet = true; break;
                case 'N':
                case 'n': std::cout << std::endl << "Podaj nowa wartosc" << std::endl; break;
                default:      std::cout << std::endl << "" << std::endl;
            }

        } else {
            param = newParam;
            newParamSet = true;        
        }
    }
}

const char* AnnotationManager::styleToString(AnnotationStyle style) {
    switch (style) {
        case AnnotationStyle::BAS: return "BAS";
        case AnnotationStyle::APA: return "APA";
        case AnnotationStyle::Harvard: return "Harvard";
        default: return "None";
    }
}

const char* AnnotationManager::categoryToString(AnnotationCategory category) {
    switch (category) {
        case AnnotationCategory::Book: return "Book";
        case AnnotationCategory::ScienceArticle:  return "Science Article";
        case AnnotationCategory::WebsiteArticle : return "Website Article";
        case AnnotationCategory::OnlineVideo : return "Online video";
        default: return "None";
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
        std::cin >> newParam;

        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (newParam == "sl") {
            // WYSWIETL LISTE DOSTEPNYCH STYLI
            std::cout << std::endl << "Lista stylow: " << std::endl;
            std::cout << "BAS" << std::endl;
            std::cout << "APA" << std::endl;
            std::cout << "Harvard" << std::endl;
            continue;
        } else if (newParam == "BAS") {
            annStyle = AnnotationStyle::BAS;
            std::cout << "Poprawnie wybrano styl" << std::endl;
            break;
        } else if (newParam == "APA") {
            annStyle = AnnotationStyle::APA;
            std::cout << "Poprawnie wybrano styl" << std::endl;
            break;
        } else if (newParam == "Harvard") {
            annStyle = AnnotationStyle::Harvard;
            std::cout << "Poprawnie wybrano styl" << std::endl;
            break;
        } else {
            std::cout << "Niestety, taki styl nie jest oblugiwany lub nie istnieje. Pamietaj, ze styl jest case sensitive" << std::endl;
            continue;
        }
    }

    while (!paramGood) {
        std::cout << "podaj kategorie adnotacji (cl dla wyswietlenia listy): ";
        std::getline(std::cin, newParam);

        if (newParam == "cl") {
            // WYSWIETL LISTE DOSTEPNYCH KATEGORII
            std::cout << std::endl << "Lista kategorii: " << std::endl;
            std::cout << "Book" << std::endl;
            std::cout << "Website article" << std::endl;
            std::cout << "Science article" << std::endl;
            std::cout << "Online video" << std::endl;
            continue;
        } else if (newParam == "Book") {
            annCat = AnnotationCategory::Book;
            std::cout << "Poprawnie wybrano kategorie" << std::endl;
            break;
        } else if (newParam == "Website article") {
            annCat = AnnotationCategory::WebsiteArticle;
            std::cout << "Poprawnie wybrano kategorie" << std::endl;
            break;
        } else if (newParam == "Science article") {
            annCat = AnnotationCategory::ScienceArticle;
            std::cout << "Poprawnie wybrano kategorie" << std::endl;
            break;
        }  else if (newParam == "Online video") {
            annCat = AnnotationCategory::OnlineVideo;
            std::cout << "Poprawnie wybrano kategorie" << std::endl;
            break;
        } else {
            std::cout << "Niestety, taka kategoria: " << newParam <<  " nie jest oblugiwana lub nie istnieje. Pamietaj, ze kategoria jest case sensitive" << std::endl;
            continue;
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