// Declare this class here
#include<iostream>
class RandomEngine {
    private:
         uint8_t length;
         bool symb;
    public:
    // constructors:
         RandomEngine();
         explicit RandomEngine(uint8_t l)
         {
              length=l;
         }
         explicit RandomEngine(bool s)
         {
              symb=s;
         }
         RandomEngine(uint8_t l,bool s)
         {
              length=l;
              symb=s;
         }

    // member functions:
         void setLength(uint8_t);
         void setSymbol(bool);
         std::string getString();
         uint8_t getLength();
         bool getSymbolStatus();
};
