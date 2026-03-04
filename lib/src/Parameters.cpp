#include <annotation/Parameters.h>

const char* styleToString(AnnotationStyle style) {
    switch (style) {
        case AnnotationStyle::BAS: return "BAS";
        case AnnotationStyle::APA: return "APA";
        case AnnotationStyle::Harvard: return "Harvard";
        default: return "None";
    }
}

const char* categoryToString(AnnotationCategory category) {
    switch (category) {
        case AnnotationCategory::Book: return "Book";
        case AnnotationCategory::Monograph :  return "Monograph";
        case AnnotationCategory::Collective : return "Collective work";
        case AnnotationCategory::OnlineArticle : return "Online article";
        case AnnotationCategory::OnlineVideo : return "Online video";
        case AnnotationCategory::LegalAct : return "Legal act";
        case AnnotationCategory::MagazineArticle : return "Magazine article";
        default: return "None";
    }
}