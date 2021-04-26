#include <iostream>

int main(int argc, char *argv[]){
    // set a limit of the number of arguments to be passed: in argc
    if(argc > 4)
    {
        // tell the user how to run the program
        std::cout<<"Usage1: passgen -L length_of_the_password_you_want\n";
        // We can add other usage messages here based on the input error committed by the user.
        return 1;
    }

    // set the length of the character set
    if(argv[1] == "-L")
    {
        int length = atoi(argv[2]);
        // generate length using length generator.

    }
    
    return 0;
}
