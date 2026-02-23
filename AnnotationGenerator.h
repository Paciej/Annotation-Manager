#ifndef ANNOTATION_GENERATOR_H
#define ANNOTATION_GENERATOR_H
#include "Parameters.h"

class AnnotationGenerator {
    public:
    virtual const char* generateAnnotation(const AnnotationData& annData) = 0;
    virtual const char* generateAnnotation(const AnnotationStyle& style, const AnnotationCategory& cat, const char* author, const char* title, int year, const char* pages = "\0") = 0;     
};
#endif