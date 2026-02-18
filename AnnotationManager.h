#include <iostream>
#include <string>

enum class AnnotationStyle {
    Harvard,
    APA,
    BAS
};

enum class AnnotationCategory {
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
    std::string pages = nullptr;
    int year;
    
    void parseRawInformation(int argCount, char *args[]);
public:
    AnnotationManager(int numOfArguments, char *arguments[]); 

    AnnotationVariables getAnnotationVariablesStruct(); 
};