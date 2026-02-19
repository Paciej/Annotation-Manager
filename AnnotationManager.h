#include "Parameters.h"

class AnnotationManager {
private:
    AnnotationStyle annStyle;    
    AnnotationCategory annCat;
    std::string author;
    std::string title;
    std::string pages;
    std::string year;

    template <typename T>
    void setSingleParamFromUser(T& param, const char* name, bool askIfGood);
    void parseRawInformation(int argCount, char *args[]);
public:
    AnnotationManager() {
        annStyle = AnnotationStyle::None;
        annCat = AnnotationCategory::None;
        author = "";
        title = "";
        pages = "";
        year = "";
    }

    AnnotationManager(int numOfArguments, char *arguments[]); 

    AnnotationVariables getAnnotationVariablesStruct(); 

    AnnotationVariables getAnnotationVariablesStruct(int argCount, char *args[]);

    void getParametersFromUser();

    void listParameters();
};