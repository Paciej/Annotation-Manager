#include "BasGenerator.h"
#include <iostream>

const char *BasGenerator::generateAnnotation(const AnnotationData& annData)
{
    std::string annotation = "";
    switch(annData.annCat) {
        case AnnotationCategory::Book : 
        annotation = annData.authors[0] + ", " + annData.title + ", " + annData.publisher + ", " + annData.place + " " + (annData.year) + ", s. " + annData.pages + ".";
        case AnnotationCategory::Monograph :
        annotation = annData.authors[0] + ", " + annData.title + ", " + annData.publisher + ", " + (annData.year) + ", s. " + annData.pages + ".";
        break;
        case AnnotationCategory::Collective :
        for (auto author : annData.authors) {
            annotation += author + ", ";
        }
        annotation += annData.title + ", " + annData.place + " " + annData.year + ", s. " + annData.pages + ".";   
        break;
        case AnnotationCategory::LegalAct :
        annotation = "Ustawa z dnia " + annData.date + " r. - " + annData.title + "(Dz.U. z " + annData.year + " r. poz. " + annData.pages + ".)."; 
        break;
        case AnnotationCategory::MagazineArticle :
        annotation = annData.authors[0] + ", " + annData.title + ", ,," + annData.publisher + "\", " + (annData.year) + ", s. " + annData.pages + ".";
        break;  
        case AnnotationCategory::OnlineArticle :
        annotation = "Zob. " + annData.authors[0] + ", " + annData.title + ", [online: " + annData.source + "], " + annData.year + ", " + annData.url + ", [dostęp: " + annData.date + "]";  
        break;
        case AnnotationCategory::OnlineVideo :
        annotation = "Zob. " + annData.authors[0] + " (reż.), " + annData.title + " (" + annData.originalTitle + "), [online: " + annData.source + "], " + annData.year + ", " + annData.url + ", [dostęp: " + annData.date + "]";  
        break; 
    }
    
    return annotation.c_str();
}

const char *BasGenerator::generateAnnotation(const AnnotationStyle &style, const AnnotationCategory &cat, const char *author, const char *title, int year, const char *pages)
{
    return nullptr;
}
