#include "BasGenerator.h"
#include <iostream>

const char *BasGenerator::generateAnnotation(const AnnotationData& annData)
{
    std::string annotation = "";
    switch(annData.annCat) {
        case AnnotationCategory::Book : 
        case AnnotationCategory::Monograph :
        annotation = annData.authors[0] + ", " + annData.title + ", " + annData.publisher + ", " + annData.place + " " + (annData.year) + ", s. " + annData.pages + ".";
        break;
        case AnnotationCategory::Collective :
        for (auto author : annData.authors) {
            annotation += author + ", ";
        }
        annotation += "TYTUL ROZDZIALU, [w:" + annData.title + "], red. IMIE REDAKTORA, " + annData.place + " " + (annData.year) + ", s. " + annData.pages + ".";  
        break;
        case AnnotationCategory::LegalAct :
        annotation = "Ustawa z dnia " + (annData.year) + " r. - " + annData.title + ", Dz.U. poz. " + annData.pages + "."; 
        break;
        case AnnotationCategory::MagazineArticle :
        annotation = annData.authors[0] + ", " + annData.title + ", ,," + annData.publisher + "\" " + (annData.year) + ", s. " + annData.pages + ".";
        break;  
        case AnnotationCategory::OnlineArticle :
        annotation = annData.authors[0] + ", " + annData.title + ", " + annData.url + "[dostęp: " + (annData.year) + "]";
        break;
        case AnnotationCategory::OnlineVideo :
        annotation = annData.authors[0] + ", " + annData.title + ", [online: " + annData.publisher + " " + (annData.year) + "]";
        break; 
    }
    
    return annotation.c_str();
}

const char *BasGenerator::generateAnnotation(const AnnotationStyle &style, const AnnotationCategory &cat, const char *author, const char *title, int year, const char *pages)
{
    return nullptr;
}
