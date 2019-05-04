#include <M6502.h>
#include <memory.h>
#include <iostream>

int main( int c, char** argv){
    M6502_memory* mem = new M6502_memory(argv[1]);
    std::cout << "argv[1]: " << argv[1] << std::endl;
    M6502_core cpu = M6502_core(mem);

    int i = 1;
    while(!cpu.brk()){
        std::cout << " count = " << i << std::endl;
        cpu.run();
        if(i%23==0){
            cpu.irq();
        }
        if(i%17==0){
            cpu.nmi();
        }
        i++;
    }
    mem->dump();

    return 0;
}