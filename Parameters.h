#include <string>

enum class AnnotationStyle {
    None,
    Harvard,
    APA,
    BAS
};

enum class AnnotationCategory {
   None,
   Book,
   WebsiteArticle,
   OnlineVideo,
   ScienceArticle 
};

struct AnnotationVariables {
    int year;
    AnnotationStyle annStyle = AnnotationStyle::None;
    AnnotationCategory annCat = AnnotationCategory::None;
    std::string author;
    std::string title;
    std::string pages = nullptr;
};

const char* styleToString(AnnotationStyle style);

const char* categoryToString(AnnotationCategory category);

