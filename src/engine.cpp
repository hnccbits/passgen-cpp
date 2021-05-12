#include "engine.h"
#include <iostream>
#include <string>
// Create definitions of the RandomEngine class here

// Constructors:
RandomEngine::RandomEngine(uint8_t l){
    length = l;
}

RandomEngine::RandomEngine(bool s){
    symbl = s;
}

RandomEngine::RandomEngine(uint8_t l, bool s){
    length = l;
    symbl = s;
}

// Methods:
void RandomEngine::setLength(uint8_t l){
    length = l;
}

uint8_t RandomEngine::getLength(){
    return length;
}

void RandomEngine::setSymbolSet(bool s){
    symbl = s;
}

bool RandomEngine::getSymbolSetStatus(){
    return symbl;
}

std::string RandomEngine::getString(){
    // Generating password for -L option

    std::string CharSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string SymblSet = "!@#$%^&*-_";
    std::string Set = "";

    char seq[100];
    std::ifstream file("/dev/urandom", std::ios::in | std::ios::binary);
    if(!file) {
        std::cout << "Error opening file\n";
    }
    file.read(seq, sizeof(char)*100);
    file.close();
    std::seed_seq seed(seq, seq+100);
    std::mt19937_64 gen(seed);
    std::uniform_int_distribution<int64_t> dist(0, L);
    

    for(int i = 0; i < getLength(); i++)
    {
        int indx = dist(gen);
        password += CharSet[indx];
    }
    return password;
}