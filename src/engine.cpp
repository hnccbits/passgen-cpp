#include "engine.h"
#include <iostream>
#include <string>
// Create definitions of the RandomEngine class here

// Create definitions of the RandomEngine class here

// Constructors:
RandomEngine::RandomEngine(uint8_t l){
    length = l;
}

RandomEngine::RandomEngine(bool s){
    
}

RandomEngine::RandomEngine(uint8_t l, bool s){
    
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
    // returning any dummy string
    return password;
}