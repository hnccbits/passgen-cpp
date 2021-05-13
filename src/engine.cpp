#include "engine.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <random>
// Create definitions of the RandomEngine class here
// Methods:
RandomEngine::RandomEngine(): gen{seed}{
    //Reading 100 bytes of data from urandom file for seed generation.
    //this part is independent of user's input, hence defined in the default contructor.
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file){
    std::cout << "Error opening file\n";
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    std::seed_seq seed(seq, seq+100);
}
RandomEngine::RandomEngine(uint8_t l,bool s): dist{0,mod}{
    length=l;
    symb=s;
    if(symb){
        mod=72;
    }
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
        ind=dist(gen);
        if(symb && alpha_num_sym[ind]!='\0'){
        password+= alpha_num_sym[ind];
        }
        else if(!symb && alpha_num[ind]!='\0'){
        password+=alpha_num[ind];
        }
     }
    return password;
} 