#include <M6502.h>
#include <memory.h>
#include <iostream>

int main( int c, char** argv){
    M6502_memory* mem = new M6502_memory(argv[1]);
    std::cout << "argv[1]: " << argv[1] << std::endl;
    M6502_core cpu = M6502_core(mem);

    while(!cpu.brk()){
        cpu.run();
    }
    mem->dump();

    return 0;
}