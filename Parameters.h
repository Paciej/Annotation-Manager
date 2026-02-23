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
    int year;
    AnnotationStyle annStyle = AnnotationStyle::None;
    AnnotationCategory annCat = AnnotationCategory::None;
    std::string author = "";
    std::string title = "";
    std::string place = "";
    std::string publisher = "";
    std::string url = "";
    std::string source = "";
    std::string pages = ""; 
};

const char* styleToString(AnnotationStyle style);

const char* categoryToString(AnnotationCategory category);

static std::unordered_map<const char*, AnnotationCategory> const catMap = { {"None", AnnotationCategory::None}, 
                                                                            {"Book", AnnotationCategory::Book}, 
                                                                            {"Collective Work", AnnotationCategory::Collective},
                                                                            {"Monograph", AnnotationCategory::Monograph},
                                                                            {"Legal act", AnnotationCategory::LegalAct},
                                                                            {"Magazine article", AnnotationCategory::MagazineArticle},
                                                                            {"Online article", AnnotationCategory::OnlineArticle},
                                                                            {"Online video", AnnotationCategory::OnlineVideo}
                                                                          };

static std::unordered_map<const char*, AnnotationStyle> const styleMap = {  {"None", AnnotationStyle::None},
                                                                            {"Harvard", AnnotationStyle::Harvard},
                                                                            {"APA", AnnotationStyle::APA},
                                                                            {"BAS", AnnotationStyle::BAS}
                                                                         };