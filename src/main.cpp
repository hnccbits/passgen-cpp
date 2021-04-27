#include <iostream>
#include <string.h>
#include "version.h"


int main(int argc, char *argv[]){
    // set a limit of the number of arguments to be passed: in argc
    if(argc > 4){
        // tell the user how to run the program
        std::cout<<"Usage1: passgen -L length_of_the_password_you_want\n";
        // We can add other usage messages here based on the input error committed by the user.
        return 1;
    }

    // set the length of the character set to default, which is 8.
    int length = 8;
    for(int i = 0; i<argc; i++){
        if(strcmp(argv[i], "-L") == 0){
            length = atoi(argv[i+1]);
        }
        if (std::string(argv[i]) == "-V"){
            std::cout << "passgen version: " << passgen_VERSION_MAJOR << "." << passgen_VERSION_MINOR  << "."<< passgen_VERSION_REVISION << "\n";
        }
            
    }
    return 0;
}