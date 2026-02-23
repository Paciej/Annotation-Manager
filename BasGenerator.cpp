#include "BasGenerator.h"
#include <iostream>

const char *BasGenerator::generateAnnotation(const AnnotationData& annData)
{
    std::string annotation = "";
    switch(annData.annCat) {
        case AnnotationCategory::Book : 
        case AnnotationCategory::Monograph :
        annotation = annData.author + ", " + annData.title + ", " + annData.publisher + annData.place + ", "  + " " + std::to_string(annData.year) + ", s. " + annData.pages + ".";
        break;
        case AnnotationCategory::Collective :
        annotation = annData.author + ", TYTUL ROZDZIALU, [w:" + annData.title + "], red. IMIE REDAKTORA, " + annData.place + " " + std::to_string(annData.year) + ", s. " + annData.pages + ".";  
        break;
        case AnnotationCategory::LegalAct :
        annotation = "Ustawa z dnia " + std::to_string(annData.year) + " r. - " + annData.title + ", Dz.U. poz. " + annData.pages + "."; 
        break;
        case AnnotationCategory::MagazineArticle :
        annotation = annData.author + ", " + annData.title + ", ,," + annData.publisher + "\" " + std::to_string(annData.year) + ", s. " + annData.pages + ".";
        break;  
        case AnnotationCategory::OnlineArticle :
        annotation = annData.author + ", " + annData.title + ", " + annData.url + "[dostęp: " + std::to_string(annData.year) + "]";
        break;
        case AnnotationCategory::OnlineVideo :
        annotation = annData.author + ", " + annData.title + ", [online: " + annData.publisher + " " + std::to_string(annData.year) + "]";
        break; 
    }
    
    return annotation.c_str();
}

const char *BasGenerator::generateAnnotation(const AnnotationStyle &style, const AnnotationCategory &cat, const char *author, const char *title, int year, const char *pages)
{
    return nullptr;
}
