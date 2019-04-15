#ifndef M6502_h
#define M6502_h

#include <stdint.h>
#include "memory.h"

class M6502_core {
    
    private:
    /*---Interrupt Routine Pointer addresses---*/
    const uint16_t IRQ_H = 0xFFFF;
    const uint16_t IRQ_L = 0xFFFE;
    const uint16_t RESET_H = 0xFFFD;
    const uint16_t RESET_L = 0xFFFC;
    const uint16_t NMI_H = 0xFFFB;
    const uint16_t NMI_L = 0xFFFA;
    /*------------------------------------------*/

    uint8_t A;      // accumulator
    uint8_t X;      // X register
    uint8_t Y;      // Y register
    uint16_t PC;    // Program Counter
    uint8_t SP;     // Stack Pointer
    uint8_t IR;     // Instruction Register

    /*---------------Status Register-------------------*/
    struct StatusRegister{
        bool    C;      // Carry Flag               SR bit 0
        bool    Z;      // Zero FLag                SR bit 1
        bool    I;      // Interrupt Disable Flag   SR bit 2
        bool    D;      // Decimal Mode Flag        SR bit 3
        bool    B;      // Break Flag               SR bit 4
        const bool U = 1;   // Unused               SR bit 5
        bool    V;      // Overflow Flag            SR bit 6
        bool    S;      // Sign Flag (N)            SR bit 7
    }SR;

    uint8_t read_SR(){
        uint8_t status = 0x20;

        if(SR.C) status |= 0x01;
        if(SR.Z) status |= 0x02;
        if(SR.I) status |= 0x04;
        if(SR.D) status |= 0x08;
        if(SR.B) status |= 0x10;
        if(SR.V) status |= 0x40;
        if(SR.S) status |= 0x80;
            
        return status;
    }

    void write_SR(uint8_t status){
        SR.C = status & 0x01;
        SR.Z = status & 0x02;
        SR.I = status & 0x04;
        SR.D = status & 0x08;
        SR.B = status & 0x10;
        SR.V = status & 0x40;
        SR.S = status & 0x80;
    }

    /*-------------------------------------------------*/

    M6502_memory* M;

    void stack_push(uint8_t);            //push to 6502 stack
    uint8_t stack_pop();                 //pop from 6502 stack
    void execute(uint8_t);              //take an opcode and execute an instruction

    /*----------------Address Helpsers-------------------*/
    /*               See SwitchCase.cpp                  */
    uint8_t read_zpg();
    uint8_t read_zpg(uint8_t);
    uint8_t read_rel();
    uint8_t read_abs();
    uint8_t read_abs(uint8_t);
    uint16_t read_ind();
    uint8_t read_ind_x();
    uint8_t read_ind_y();
    /*---------------------------------------------------*/

    public:

    M6502_core(M6502_memory*);

    void run();                         //fetch and execute an instruction

    void reset();                       //reset the CPU

    void irq();                         //interrupt

    void nmi();                         //non maskable interrupt
};

#endif
