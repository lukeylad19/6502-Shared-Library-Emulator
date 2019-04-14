#include <M6502.h>
#include <memory.h>

int main( int c, char** argv){
    M6502_memory* mem = new M6502_memory("./test/test_nop.bin");
    M6502_core cpu = M6502_core(mem);
    cpu.run();

    return 0;
}