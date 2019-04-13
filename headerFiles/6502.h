#include <stdint.h>
#include "memory.h"

class 6502_core {
    
    private:
    /*---Interrupt Routine Pointer addresses---*/
    const uint16_t IRQ_H = 0xFFFF;
    const unit16_t IRQ_L = 0xFFFE;
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
    enum SR{
        bool    C;      // Carry Flag               SR bit 0
        bool    Z;      // Zero FLag                SR bit 1
        bool    I;      // Interrupt Disable Flag   SR bit 2
        bool    D;      // Decimal Mode Flag        SR bit 3
        bool    B;      // Break Flag               SR bit 4
        const bool U = 1;   // Unused               SR bit 5
        bool    V;      // Overflow Flag            SR bit 6
        bool    S;      // Sign Flag                SR bit 7

        uint_t value(){
            uint8_t status = 0x20;

            if(C) status |= 0x01;
            if(Z) status |= 0x02;
            if(I) status |= 0x04;
            if(D) status |= 0x08;
            if(B) status |= 0x10;
            if(V) status |= 0x40;
            if(S) status |= 0x80;
            
            return status;
        }
    }
    /*-------------------------------------------------*/

    6502_memory* M;

    void stack_push(uint8_t);            //push to 6502 stack
    uint8_t stack_pop();                 //pop from 6502 stack
    void exectute(uint8_t);              //take an opcode and execute an instruction

    public:

    void 6502_core(6502_memory);

    void run();                         //fetch and execute an instruction

    void reset();                       //reset the CPU

    void irq();                         //interrupt

    void nmi();                         //non maskable interrupt
};
