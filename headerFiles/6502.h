#include <stdint.h>

class 6502_core {
    
    private:
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
        }
    }

    /*-------------------------------------------------*/

    public:

    void 6502_core();

    void reset();

    void irq();

    void nmi();
};