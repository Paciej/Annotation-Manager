#include "Parameters.h"

class AnnotationGenerator {
    public:
    
    virtual void generateAnnotation(AnnotationData annVar);
    virtual void generateAnnotation(AnnotationStyle style, AnnotationCategory cat, const char* author, const char* title, int year, const char* pages = "\0");     
};