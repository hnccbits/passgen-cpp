#include <iostream>
#include <cstring>
#include "engine.h"
#include "version.h"

void print_usage() {
    std::cout << "Usage:\n";
    std::cout << "passgen -L <length>       generates a random password with default character set of given length\n";
	std::cout << "Example: passgen -L 20    generates a random password with default character set of length 20\n";
	std::cout << "passgen -S                generates a random password with all character set of default length 8\n";
	std::cout << "passgen -S -L <length>    generates a random password with all characters set of given length\n";
	std::cout << "Example: passgen -S -L 20 generates a random password with all characters set of length 20\n";
	std::cout << "passgen -V	      prints the version of this tool\n";
}

int main(int argc, char *argv[]){
    // set a limit of the number of arguments to be passed: in argc
    if(argc > 4){
        // tell the user how to run the program
        std::cerr << "Illegal usage!\n";
        print_usage();
        return 1;
    }

    // set the length of the character set to default, which is 8.
    int length = 8;

    // set symbol set
    bool symbol_set = false;

    for(int i = 1; i<argc; i++) {
        if(strcmp(argv[i], "-S") == 0) {
            if(!symbol_set) {
                symbol_set = true;
            } else {
                std::cerr << "Illegal usage: Multiple -S flags\n";
                return 2;
            }
        } else if(strcmp(argv[i], "-L") == 0){
            if(i == argc - 1) {
                std::cerr << "Illegal usage: password length not provided with -L option\n";
                return 2;
            }
            size_t pos;
            try {
                length = std::stoi(argv[i+1], &pos);
            } catch (std::invalid_argument &e) {
                std::cerr << "Bad argument for password length\n";
                return 2;
            } catch (std::out_of_range &e) {
                std::cerr << "Integer out of range\n";
                return 2;
            }
            if(pos != strlen(argv[i+1])) {
                // This is a rare case when a string like "45jkl" is parsed to 45 and not bad input
                std::cerr << "Bad argument for password length\n";
                return 2;
            }
            if(length < 1 || length > 128) {
                std::cerr << "password length must be in the range [1,128]\n";
                return 2;
            }

            // If all goes right, we have a valid length
            break;
        } else if (strcmp(argv[i], "-V") == 0){
            std::cout << "passgen version: " << passgen_VERSION_MAJOR << "." << passgen_VERSION_MINOR  << "."<< passgen_VERSION_REVISION << "\n";
            break;
        } else if (strcmp(argv[i], "-H") == 0){
			print_usage();
            break;
        } else {
            std::cout << "Unknown option: " << argv[i] << std::endl;
            print_usage();
            return 2;
        }
    }
    RandomEngine r1(length,symbol_set);
    //Printing randomly generated password to stdout.
    std::cout<<r1.getString()<<std::endl;
    
    return 0;
}