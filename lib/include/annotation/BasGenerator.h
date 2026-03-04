#ifndef BAS_GENERATOR_H
#define BAS_GENERATOR_H
#include "AnnotationGenerator.h"

class BasGenerator : public AnnotationGenerator {
    public:
    const char* generateAnnotation(const AnnotationData& annData) override;
    const char* generateAnnotation(const AnnotationStyle& style, const AnnotationCategory& cat, const char* author, const char* title, int year, const char* pages = "\0") override;     
};
#endif