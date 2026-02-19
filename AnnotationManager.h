#include <iostream>
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
    AnnotationStyle annotationStyle;
    AnnotationCategory annotationCategory;
    std::string author;
    std::string title;
    std::string pages = nullptr;
};

class AnnotationManager {
private:
    AnnotationStyle annStyle;    
    AnnotationCategory annCat;
    std::string author;
    std::string title;
    std::string pages;
    int year;

    template <typename T>
    void setSingleParamFromUser(T& param, const char* name, bool askIfGood);
    const char* categoryToString(AnnotationCategory category);
    const char* styleToString(AnnotationStyle style);
    void parseRawInformation(int argCount, char *args[]);
public:
    AnnotationManager() {
        annStyle = AnnotationStyle::None;
        annCat = AnnotationCategory::None;
        author = "";
        title = "";
        pages = "";
        year = 0;
    }

    AnnotationManager(int numOfArguments, char *arguments[]); 

    AnnotationVariables getAnnotationVariablesStruct(); 

    AnnotationVariables getAnnotationVariablesStruct(int argCount, char *args[]);

    void getParametersFromUser();

    void listParameters();
};