#include <iostream>
#include <stdint.h>
#include <string>
#include "M6502.h"
#include "memory.h"

M6502_core::M6502_core(M6502_memory *mem){              //attach memory and reset
    M = mem;
    reset();
    std::cout << "PC is: " << PC << std::endl;
}

void M6502_core::stack_push(uint8_t byte){              //push to 6502's Stack
    M->write(0x0100+SP,byte);
    if(SP== 0x00){
        SP = 0xFF;
    }
    else{
        SP--;
    }
}

uint8_t M6502_core::stack_pop(){                        //pop from the 6502's stack
    if(SP == 0xFF){
        SP = 0x00;
    }
    else SP++;
    return M->read(0x0100 + SP);
}

void M6502_core::run(){                                  //execute 1 instruction
    IR= M->read(PC); 
    std::cout<< "PRE -- " << "IR: " << unsigned(IR) <<std::endl;                //fetch instruction
    std::cout<< "SR.C: " << SR.C << " SR.Z: " << SR.Z << " SR.I: " << SR.I << " SR.D: " << SR.D;
    std::cout<< " SR.B: " << SR.B << " SR.V: " << SR.V << " SR.S: " << SR.S << std::endl;
    std::cout<< std::hex << "A: " << unsigned(A) << " X: " << unsigned(X) << " Y: " << unsigned(Y) << " SP: " << unsigned(SP) << " PC: " << unsigned(PC) << std::endl;
    execute(IR);
    PC++;
    std::cout<< "POST -- ";
    std::cout<< "SR.C: " << SR.C << " SR.Z: " << SR.Z << " SR.I: " << SR.I << " SR.D: " << SR.D;
    std::cout<< " SR.B: " << SR.B << " SR.V: " << SR.V << " SR.S: " << SR.S << std::endl;
    std::cout<< std::hex << "A: " << unsigned(A) << " X: " << unsigned(X) << " Y: " << unsigned(Y) << " SP: " << unsigned(SP) << " PC: " << unsigned(PC) << std::endl << std::endl;
}

void M6502_core::reset(){

    A=0x00;                                              //clear the registers AXY
    X=0x00;
    Y=0x00;

    PC = (M->read(RESET_H)<<8) +M->read(RESET_L);        //reset the program counter
    std::cout << "set PC to: " << PC << std::endl;

    SP = 0xFD;                                           //reset the stack pointer
    write_SR(0x20);                                      //reset the status register
}

void M6502_core::irq(){
    if(!SR.I){                                           //check to see if interrupts are disabled
        SR.B = false;                                    //set break false
        stack_push((PC >> 8)& 0xFF);                     //push upper byte of PC to stack
        stack_push(PC&0xFF);                             //push lower byte of PC to stack
        stack_push(read_SR());                           //push status register to stack
        SR.I = true;                                     //disable interrupts
        PC = ((M->read(IRQ_H)<<8)+M->read(IRQ_L));       //update PC with IRQ routine
    }
}

void M6502_core::nmi(){
    SR.B = false;                                        //set break false
    stack_push((PC >> 8)& 0xFF);                         //push upper byte of PC to stack
    stack_push(PC&0xFF);                                 //push lower byte of PC to stack
    stack_push(read_SR());                               //push status register to stack
    SR.I = true;                                         //disable interrupts
    PC = ((M->read(NMI_H)<<8)+M->read(NMI_L));           //update PC with NMI routine
}

/*void M6502_core::execute(uint8_t val){
    std::cout << val <<"execute" << std::endl;

}*/
