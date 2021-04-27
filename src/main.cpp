#include <iostream>
#include <string.h>
#include "version.h"

int main(int argc, char *argv[]){
    for (int i = 0; i < argc; ++i){
        if (strcmp(argv[i],"-V") == 0){
            std::cout << "passgen version: " << passgen_VERSION_MAJOR << "." << passgen_VERSION_MINOR  << "."<< passgen_VERSION_REVISION << "\n";
        }
    }
    return 0;
}