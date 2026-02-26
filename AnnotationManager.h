#ifndef ANNOTATION_MANAGER_H
#define ANNOTATION_MANAGER_H
#include "Parameters.h"

class AnnotationManager {
private:
    AnnotationData annData;

    template <typename T>
    void getSingleParamFromUser(T& param, const char* name, bool askIfGood);
    void parseRawInformation(int argCount, char *args[]);
    void getBASParameters();
public:
    AnnotationManager();
    AnnotationManager(int numOfArguments, char *arguments[]); 

    AnnotationData getAnnotationVariablesStruct(); 

    AnnotationData getAnnotationVariablesStruct(int argCount, char *args[]);

    void getParametersFromUser();

    void listParameters();
};
#endif