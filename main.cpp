#include <iostream>
#include <string>
#include "AnnotationManager.h"

int main(int argc, char *argv[]) {

    std::cout << "number of arguments: " << argc << std::endl;

    for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "] : " << argv[i] << std::endl;
    }

    AnnotationManager manager = AnnotationManager();

    if (argc < 2) {
        manager.getParametersFromUser();
        manager.listParameters();
    }

}