/*
Copyright <2021> <Hackathon and Coding Club, BIT Sindri (hnccbits@gmail.com)>

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "engine.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <functional>
#include <random>
#include <filesystem>

//Create definitions of the RandomEngine class here
//Methods:
RandomEngine::RandomEngine():length((uint8_t)8),symb(false),mod(symb?73:63){
    //Reading 100 bytes of data from urandom file for seed generation.
    //this part is independent of user's input, hence defined in the default contructor.
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file){
        throw std::filesystem::filesystem_error("Error opening file",std::error_code());
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    std::seed_seq seed(seq, seq+100);
    gen = std::make_unique<std::mt19937_64>(seed);
    dist = std::make_unique<std::uniform_int_distribution<int64_t>>(0, mod);
}
RandomEngine::RandomEngine(uint8_t l,bool s): length(l), symb(s),mod(symb?73:63){
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file){
        throw std::filesystem::filesystem_error("Error opening file",std::error_code());
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    std::seed_seq seed(seq, seq+100);
    gen = std::make_unique<std::mt19937_64>(seed);
    dist = std::make_unique<std::uniform_int_distribution<int64_t>>(0, mod);
}
RandomEngine::RandomEngine(uint8_t l):length(l),mod(symb?73:63){
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file){
        throw std::filesystem::filesystem_error("Error opening file",std::error_code());
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    std::seed_seq seed(seq, seq+100);
    gen = std::make_unique<std::mt19937_64>(seed);
    dist = std::make_unique<std::uniform_int_distribution<int64_t>>(0, mod);
}

RandomEngine::RandomEngine(bool s): symb(s),mod(symb?73:63){
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file){
        throw std::filesystem::filesystem_error("Error opening file",std::error_code());
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    std::seed_seq seed(seq, seq+100);
    gen = std::make_unique<std::mt19937_64>(seed);
    dist = std::make_unique<std::uniform_int_distribution<int64_t>>(0, mod);
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
        auto dice = std::bind(*dist,*gen);
        while(password.length()!=length){
        password="";
        for(int i=0;i<length;i++){
        uint8_t indx = dice();
        if(symb && alpha_num_sym[indx]!='\0'){
        password+= alpha_num_sym[indx];
        }
        else if(!symb && alpha_num[indx]!='\0'){
        password+=alpha_num[indx];
        }
     }
        }
    return password;
} 
