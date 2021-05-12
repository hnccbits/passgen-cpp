// Declare this class here
#include<iostream>
class RandomEngine {
    private:
         uint8_t length=0;
         bool symb=false;
    public:
    // constructors:
         RandomEngine();
         explicit RandomEngine(uint8_t l);
         explicit RandomEngine(bool s);
         RandomEngine(uint8_t l,bool s);

    // member functions:
         void setLength(uint8_t);
         void setSymbol(bool);
         std::string getString();
         u_int8_t getLength();
         bool getSymbolStatus();
};