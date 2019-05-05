#include "memory.h"
#include "M6502.h"

extern "C"                          //for compatibility with Python ctypes
{
    M6502_memory* M6502_memory_new(std::string rom){return new M6502_memory(rom);}
    uint8_t M6502_memory_read(M6502_memory* m,uint16_t addr){return m->read(addr);}
    uint16_t M6502_memory_readWord(M6502_memory* m,uint16_t addr){return m->read(addr);}
    void M6502_memory_write(M6502_memory* m,uint16_t addr,uint8_t data){m->write(addr,data);}
    void M6502_memory_dump(M6502_memory* m){m->dump();}
    M6502_core* M6502_core_new(M6502_memory* m){return new M6502_core(m);}
    bool M6502_core_brk(M6502_core* cpu){return cpu->brk();}
    void M6502_core_run(M6502_core* cpu){cpu->run();}
    void M6502_core_reset(M6502_core* cpu){cpu->reset();}
    void M6502_core_irq(M6502_core* cpu){cpu->irq();}
    void M6502_core_nmi(M6502_core* cpu){cpu->nmi();}
}