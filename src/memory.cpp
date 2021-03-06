#include "memory.h"
#include <stdint.h>
#include <iostream>
#include <fstream>

M6502_memory::M6502_memory(std::string romfile){
    char* buffer;
    long size;
    std::cout << "trying to load ROM" << std::endl;
    std::ifstream rom (romfile,std::ios::in|std::ios::binary|std::ios::ate);
    if(rom.good()){
        size = rom.tellg();
        rom.seekg(0,std::ios::beg);
        buffer = new char[size];
        rom.read(buffer,size);
        rom.close();
        std::cout << "File Opened Succesfully" << std::endl;
    }
    else{
        std::cout << "Error Opening File" << std::endl;
    }

    uint16_t start = (1 << 16)-size;
    for(int i=0;(start+i)<(1<<16);i++){
        M[start+i] = buffer[i];
    }

}

void M6502_memory::dump(){
    std::ofstream outfile ("memory_dump.txt");
    outfile <<"MEMORY DUMP: "<<std::endl;
    for(int i=0; i<(1<<16);i++){
        outfile << std::hex << unsigned(i) << ": "<< unsigned(M[i]) << std::endl;
    }
    outfile.close();
}

uint8_t M6502_memory::read(uint16_t addr){
    return M[addr];
}

uint16_t M6502_memory::readWord(uint16_t addr){
    uint16_t temp = M[addr+1]<<8;
    temp = temp +M[addr];
    return temp;
}

void M6502_memory::write(uint16_t addr, uint8_t byte){
    if(addr < (1<<16))
        M[addr] = byte;
}
