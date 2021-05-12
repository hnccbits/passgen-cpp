#include <iostream>
#include <cstring>
#include<fstream>
#include<random>
#include "version.h"
#include "engine.h"

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
    bool symbol_set = false, askd_VorH = false;

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

    // Generate the seed values:
    char seq[100];
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file) {
        std::cout << "Error opening file\n";
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    
    std::seed_seq seed(seq, seq+100);

    std::mt19937_64 gen(seed);

    std::uniform_int_distribution<int64_t> dist(0, 100000);
    
    // Instansiate the RadomEngine class: for various cofigurations.
    // 1. Instansiate the class RandomEngine for -L option.
    RandomEngine el((uint8_t)62);
    el.setSymbolSet(symbol_set);
    // set the length of the password:
    el.setLength(length);
    if(!el.getSymbolSetStatus() && !askd_VorH){
        
        el.charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        
        // the porpose of this loop is to generate random indexs in a vector.
        // then use those random indexes to find the corresponding character in the Set string.
        for(int i = 0; i < el.getLength(); i++)
        {
            int indx = dist(gen) % 62;
            el.indx.push_back(indx);
        }

        // generate the desired random password:
        std::string password = el.password;
        std::string Set = el.charSet;
        for(uint8_t i : el.indx){
            password += Set[i];
        }

        // print the password:
        el.password = password;
        std::cout<<el.getString()<<std::endl;
    }
    return 0;
}
