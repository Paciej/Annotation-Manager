#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <string>
#include <unordered_map>

enum class AnnotationStyle {
    None,
    Harvard,
    APA,
    BAS
};

enum class AnnotationCategory {
   None,
   Book,
   Monograph,
   Collective,
   OnlineArticle,
   MagazineArticle,
   OnlineVideo,
   LegalAct
};

struct AnnotationData {
    AnnotationStyle annStyle = AnnotationStyle::None;
    AnnotationCategory annCat = AnnotationCategory::None;
    std::string year = "2025";
    std::string date = "01.01.2000";
    std::string author = "_author_";
    std::string title = "_title_";
    std::string originalTitle = "_original title_";
    std::string place = "_place_";
    std::string publisher = "_publisher_";
    std::string url = "_url_";
    std::string source = "_source_";
    std::string pages = "_pages_"; 
};

const char* styleToString(AnnotationStyle style);
const char* categoryToString(AnnotationCategory category);

static std::unordered_map<const char*, AnnotationCategory> const catMap = { 
    {"Book", AnnotationCategory::Book}, 
    {"Collective Work", AnnotationCategory::Collective},
    {"Monograph", AnnotationCategory::Monograph},                                                                           
    {"Legal act", AnnotationCategory::LegalAct},
    {"Magazine article", AnnotationCategory::MagazineArticle},
    {"Online article", AnnotationCategory::OnlineArticle},
    {"Online video", AnnotationCategory::OnlineVideo}
};

static std::unordered_map<const char*, AnnotationStyle> const styleMap = {  
    {"Harvard", AnnotationStyle::Harvard},
    {"APA", AnnotationStyle::APA},
    {"BAS", AnnotationStyle::BAS}
};
#endif