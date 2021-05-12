// Declare this class here
#include <cstring>
#include <iostream>
class RandomEngine {
    private:
         uint8_t length;
         bool symb;
         char seq[100];
         uint8_t mod=62;
         char alpha_num[63]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
         char alpha_num_sym[73]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*-_";
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
