// Declare this class here
#include <cstring>
#include <iostream>
#include <random>
class RandomEngine {
    private:
         uint8_t length;
         bool symb;
         char seq[100];
         uint8_t mod=62;
         uint8_t ind;
         char alpha_num[63]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
         char alpha_num_sym[73]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*-_";
         std::mt19937_64 gen;
         std::uniform_int_distribution<int64_t> dist; 
         std::seed_seq seed;
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
         RandomEngine(uint8_t l,bool s);
// member functions:
         void setLength(uint8_t);
         void setSymbol(bool);
         std::string getString();
         uint8_t getLength();
         bool getSymbolStatus();
};