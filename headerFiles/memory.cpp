#include "memory.h"

6502_memory::6502_memory(string romfile){
    char* buffer;
    long size;
    std::ifstream rom (romfile,std::ios:in|std::ios::binary|std::ios:ate);
    if(rom.good()){
        size = rom.tellg();
        rom.seekg(0,std::ios::beg);
        buffer = new char[size];
        rom.read(buffer,size);
        rom.close();
    }
    else{
        std::cout << "Error Opening File" << endl;
    }

    uint16_t start = (1 << 16)-size;
    for(i=0;(start+i)<size;i++){
        M[start+i] = buffer[i];
    }
}

uint8_t 6502_memory::read(uint16_t addr){
    return M[addr];
}

uint16_t 6502_memory::readWord(uint16_t addr){
    uint16_t temp = M[addr+1]<<8;
    temp = temp +M[addr];
}

void 6520_memory::write(uint16_t addr, uint8_t byte){
    if(addr < (1<<16))
        M[addr] = byte;
}