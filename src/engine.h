// Define this class here.
#include <vector>
#include <string>
class RandomEngine {
    
    private: 
        uint8_t length = 0;
        bool symbl = false;

    public:
        std::vector<uint8_t>indx = {};
        std::string charSet = "";
        std::string symblcharSet = "";
        std::string password = "";
    // Constructors:
        explicit RandomEngine(uint8_t l); // To set the generator for the specific length
        explicit RandomEngine(bool s); // To turn on symbol character set. Length remains default.
        RandomEngine(uint8_t l, bool s); // To set length and symbol character set.

    // Methods:
        void setLength(uint8_t); // Set the length
        void setSymbolSet(bool); // Turn on symbols
        std::string getString(); // Returns a random string with configured options
        uint8_t getLength();  // Return length of the generator
        bool getSymbolSetStatus();  // Returns true if symbols are on

};