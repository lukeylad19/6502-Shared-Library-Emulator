#ifndef memory_h
#define memory_h

#include <stdint.h>
#include <iostream>
#include <fstream>

class M6502_memory {
    private:
    uint8_t M[1 << 16];             //the actual memory array

    public:
    M6502_memory(std::string);       //load a rom into our address space

    uint8_t read(uint16_t);         //read a byte
    uint16_t readWord(uint16_t);    //read a word 
    void write(uint16_t,uint8_t);   //write a byte 
    void dump();                    //dump memory with cout
};

#endif
