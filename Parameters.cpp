#include "Parameters.h"

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
        case AnnotationCategory::ScienceArticle:  return "Science Article";
        case AnnotationCategory::WebsiteArticle : return "Website Article";
        case AnnotationCategory::OnlineVideo : return "Online video";
        default: return "None";
    }
}