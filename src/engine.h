// Define this class here.
class RandomEngine{
    private:
    uint8_t length;
    bool symb;
    public:
    //constructors:
    RandomEngine();
    RandomEngine(uint8_t l);
    RandomEngine(bool s);
    RandomEngine(uint8_t l,bool s);
    //member functions:
    void setLength(uint8_t);
    void setSymbol(bool);
    std::string getString();
    uint8_t getLength();
    bool getSymbolStatus();
};