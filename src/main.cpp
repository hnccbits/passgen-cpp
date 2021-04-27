#include <iostream>
#include <string.h>

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
    int length = 0;
    for(int i = 0; i<argc; i++)
    {
        if(strcmp(argv[i], "-L") == 0)
        {
            // And since the length entered by the user may be after '-S' so we
            // have to take another loop to identify where it is.
            for(int j = i; j<argc; j++)
            {
                if(isdigit(argv[i]))
                    length = atoi(argv[i]);
            }
        }
    }
    
    return 0;
}
