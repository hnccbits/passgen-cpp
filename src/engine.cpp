#include "engine.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <functional>
#include <random>
// Create definitions of the RandomEngine class here
// Methods:
RandomEngine::RandomEngine(): gen{NULL},dist{NULL}{
    //Reading 100 bytes of data from urandom file for seed generation.
    //this part is independent of user's input, hence defined in the default contructor.
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file){
    std::cout << "Error opening file\n";
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    std::seed_seq seed(seq, seq+100);
    std::mt19937_64 gen(seed);
    std::uniform_int_distribution<int64_t> dist(0,mod); 
}
RandomEngine::RandomEngine(uint8_t l,bool s): length(l), symb(s), dist{NULL},mod(symb?73:63){
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file){
    std::cout << "Error opening file\n";
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    std::seed_seq seed(seq, seq+100);
    std::mt19937_64 gen(seed);
    std::uniform_int_distribution<int64_t> dist(0,mod); 
}
RandomEngine::RandomEngine(uint8_t l): length(l),mod(symb?73:63){
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file){
    std::cout << "Error opening file\n";
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    std::seed_seq seed(seq, seq+100);
    std::mt19937_64 gen(seed);
    std::uniform_int_distribution<int64_t> dist(0,mod); 
}
  RandomEngine::RandomEngine(bool s): symb(s),mod(symb?73:63){
     std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file){
    std::cout << "Error opening file\n";
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    std::seed_seq seed(seq, seq+100);
    std::mt19937_64 gen(seed);
    std::uniform_int_distribution<int64_t> dist(0,mod); 
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
        for(int i=0;i<length;i++){
        auto dice = std::bind(*dist,*gen);
        int indx = dice();
        if(symb && alpha_num_sym[indx]!='\0'){
        password+= alpha_num_sym[indx];
        }
        else if(!symb && alpha_num[indx]!='\0'){
        password+=alpha_num[indx];
        }
     }
    return password;
} 