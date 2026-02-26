#include "AnnotationManager.h"
#include <iostream>

template <typename T>
void AnnotationManager::getSingleParamFromUser(T& param, const char* name, bool askIfGood) {
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
        std::cout << "podaj kategorie adnotacji (ls dla wyswietlenia listy): ";
        std::getline(std::cin, newParam);

        if (newParam == "ls") {
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

    switch (this->annData.annStyle) {
        case AnnotationStyle::BAS : getBASParameters(); break;
        case AnnotationStyle::APA : std::cout << "Nie obsługujemy jeszcze stylu APA" << std::endl; break;
        case AnnotationStyle::Harvard : std::cout << "Nie obsługujemy jeszcze stylu Harvard" << std::endl; break;
        default : std::cout << "Coś poszło nie tak" << std::endl; break;
    }

   // getSingleParamFromUser(this->annData.author, "Autor", 0);
   // getSingleParamFromUser(this->annData.title, "tytul", 0);
   // getSingleParamFromUser(this->annData.date, "rok", 0);
   // getSingleParamFromUser(this->annData.pages, "strony", 0);
   // getSingleParamFromUser(this->annData.place, "Miejsce", 0);    
   // getSingleParamFromUser(this->annData.publisher, "Wydawca", 0);    
   // getSingleParamFromUser(this->annData.url, "Url", 0);    
}

void AnnotationManager::listParameters()
{
    std::cout << std::endl << "Wprowadzone dane: " << std::endl;
    std::cout << "Styl: " << styleToString(this->annData.annStyle) << std::endl;
    std::cout << "Kategoria: " << categoryToString(this->annData.annCat) << std::endl;
    std::cout << "Autor: " << this->annData.author << std::endl;
    std::cout << "Tytul: " << this->annData.title << std::endl;
    std::cout << "Oryginalny tytul: " << this->annData.originalTitle << std::endl;
    std::cout << "Rok: " << this->annData.year << std::endl;
    std::cout << "Data: " << this->annData.date << std::endl;
    std::cout << "Wydawca: " << this->annData.publisher << std::endl;
    std::cout << "Miejsce: " << this->annData.place << std::endl;
    std::cout << "Strony: " << this->annData.pages << std::endl;
    std::cout << "Zrodlo: " << this->annData.source << std::endl;
    std::cout << "url: " << this->annData.url << std::endl;
}

void AnnotationManager::parseRawInformation(int argCount, char *args[]) {
    
}

void AnnotationManager::getBASParameters()
{
    std::string desc;
    getSingleParamFromUser(annData.author, "Autor (imie i nazwisko)", 0);
    desc = (annData.annCat == AnnotationCategory::OnlineVideo) ? "Polski tytul" : "Tytul"; 
    getSingleParamFromUser(annData.title, desc.c_str(), 0);
    if (annData.annCat == AnnotationCategory::OnlineVideo) {
        getSingleParamFromUser(annData.originalTitle, "Oryginalny tytul", 0);
    }

    getSingleParamFromUser(annData.year, "Rok wydania", 0);
    if (annData.annCat == AnnotationCategory::Book || annData.annCat == AnnotationCategory::Monograph) {
        getSingleParamFromUser(annData.publisher, "wydawca", 0);
    }

    if (annData.annCat == AnnotationCategory::Book || annData.annCat == AnnotationCategory::Collective) {
        getSingleParamFromUser(annData.place, "miejsce wydania", 0);
    }

    if (annData.annCat != AnnotationCategory::OnlineVideo) {
        getSingleParamFromUser(annData.pages, "strony", 0);
    }

    if (annData.annCat == AnnotationCategory::OnlineArticle || annData.annCat == AnnotationCategory::OnlineVideo) {
        getSingleParamFromUser(annData.source, "platforma", 0);
        getSingleParamFromUser(annData.date, "Data dostepu (dd.MM.yyyy)", 0);
        desc = (annData.annCat == AnnotationCategory::OnlineArticle) ? "url do artykulu" : "url do imdb"; 
        getSingleParamFromUser(annData.url, desc.c_str(), 0); 
    }

    if (annData.annCat == AnnotationCategory::LegalAct) {
        getSingleParamFromUser(annData.date, "data ustawy", 0);
    }
}
