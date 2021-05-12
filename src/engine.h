// Define this class here.
#include <iostream>
#include <cstring>
#include<fstream>
#include<random>
class RandomEngine {
    
    private: 
        uint8_t length = 0;
        bool symbl = false;
        std::string password = "";
        int L=62;
        char seq[100];

    public:
    // Constructors:
        RandomEngine();
        RandomEngine(uint8_t l); // To set the generator for the specific length
        RandomEngine(bool s); // To turn on symbol character set. Length remains default.
        RandomEngine(uint8_t l, bool s); // To set length and symbol character set.

    // Methods:
        void setLength(uint8_t); // Set the length
        void setSymbolSet(bool); // Turn on symbols
        std::string getString(); // Returns a random string with configured options
        uint8_t getLength();  // Return length of the generator
        bool getSymbolSetStatus();  // Returns true if symbols are on

};
