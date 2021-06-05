/*
Copyright <2021> <Hackathon and Coding Club, BIT Sindri (hnccbits@gmail.com)>

MIT license

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include <iostream>
#include <cstring>
#include <fstream>
#include "engine.h"
#include "version.h"

void print_usage() {
    std::cout << "Usage:\n";
    std::cout << "passgen -L <length>       generates a random password with default character set of given length\n";
	std::cout << "Example: passgen -L 20    generates a random password with default character set of length 20\n";
	std::cout << "passgen -S                generates a random password with all character set of default length 8\n";
	std::cout << "passgen -S -L <length>    generates a random password with all characters set of given length\n";
	std::cout << "Example: passgen -S -L 20 generates a random password with all characters set of length 20\n";
    std::cout << "passgen -F <file path> -S -L <length>    generates a random password with all characters set of given length in a text file with absolute path\n";
    std::cout << "Example: passgen -F ~/Documents/pass.txt -S -L 20   generates a random password with all characters set of length 20 in a text file named pass.txt, in the Documents directory\n";
	std::cout << "passgen -V	      prints the version of this tool\n";
}

int main(int argc, char *argv[]){
    // set a limit of the number of arguments to be passed: in argc
    if(argc > 6){
        // tell the user how to run the program
        std::cerr << "Illegal usage!\n";
        print_usage();
        return 1;
    }

    // set the length of the character set to default, which is 8.
    int length = 8;

    // set symbol set
    bool symbol_set = false,save_pass=false;

    //set file path for writing password to current directory as default.
    std::string file_path ;

    for(int i = 1; i<argc; i++) {
        if(strcmp(argv[i],"-F")==0){
            if(!save_pass){
                save_pass = true;
                file_path = argv[i+1];
                i++;
            }
            else{
                std::cerr << "Illegal usage: Multiple -F flags\n";
                return 2;
            }
        } 
        else if(strcmp(argv[i], "-S") == 0) {
            if(!symbol_set) {
                symbol_set = true;
            } else {
                std::cerr << "Illegal usage: Multiple -S flags\n";
                return 2;
            }
        }
        else if(strcmp(argv[i], "-L") == 0){
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
            return 2;
        } else if (strcmp(argv[i], "-H") == 0){
			print_usage();
            return 0;
        } else {
            std::cout << "Unknown option: " << argv[i] << std::endl;
            print_usage();
            return 0;
        }
    }
    RandomEngine r1(length,symbol_set);
    if(!save_pass){
    //Printing randomly generated password to stdout.
        std::cout<<r1.getString()<<std::endl;
    }
    else{
        std::ofstream file_stream;
        file_stream.open(file_path);
        if(!file_stream){
             std::cerr << "Invalid File Path. Please try again.\n";
             return 2;
        }
        else{
        file_stream << r1.getString()<<std::endl;
        std::cout<<"Password generated and saved at required file.\n";
        }
        file_stream.close();
    }
    return 0;
}
