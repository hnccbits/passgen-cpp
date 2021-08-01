/*
Copyright <2021> <Hackathon and Coding Club, BIT Sindri (hnccbits@gmail.com)>

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once
#include <cstring>
#include <iostream>
#include <random>
#include <memory>
class RandomEngine {
    private:
         uint8_t length;
         bool symb;
         char seq[100];
         uint8_t mod=62;
         const char alpha_num[63]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
         const char alpha_num_sym[73]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*-_";
         std::shared_ptr<std::mt19937_64> gen;
         std::shared_ptr<std::uniform_int_distribution<int64_t>> dist;
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
         uint8_t getLength();
         bool getSymbolStatus();
};
