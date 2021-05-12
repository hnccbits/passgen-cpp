#include "engine.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
// Create definitions of the RandomEngine class here
// Methods:
RandomEngine::RandomEngine(){
    //Reading 100 bytes of data from urandom file for seed generation.
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file){
    std::cout << "Error opening file\n";
    }
    file.read(seq, sizeof(char)*100);
    file.close();
}
void RandomEngine::setLength(uint8_t l){
    length = l;
}
uint8_t RandomEngine::getLength(){
    return length;
}
void RandomEngine::setSymbol(bool s){
    symb = s;
}
bool RandomEngine::getSymbolStatus(){
    return symb;
}
std::string RandomEngine::getString(){
        //password generation:
        std::string password;
        std::seed_seq seed(seq, seq+100);
        std::mt19937_64 gen(seed);
        if(symb){
            mod=72;
        }
        std::uniform_int_distribution<int64_t> dist(0, mod);
        for(int i=0;i<length;i++){
        uint8_t ind=dist(gen);
        if(symb){
        if(alpha_num_sym[ind]!='\0'){
        password+= alpha_num_sym[ind];
            }
        }
        else{
        if(alpha_num[ind]!='\0'){
        password+=alpha_num[ind];
            }
        }
     }

    return password;
} 
