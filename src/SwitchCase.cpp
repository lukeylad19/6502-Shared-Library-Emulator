#include <iostream>
#include <string>
#include "instruction.h"
#include "M6502.h"
//#include "opcode.h"
//void execute(uint8_t);

/*------------------------------------Addressing Helpers------------------------------------------*/
uint8_t M6502_core::read_zpg(){                             //read using zero page addressing
    return M->read(0x0000+(M->read(++PC)));
}

uint8_t M6502_core::read_zpg(uint8_t index){                //read using indexed zero page addressing pass X or Y register
    return M->read(0x0000+(M->read(++PC))+index);
}

uint8_t M6502_core::read_rel(){                             //read using relative addressing
    uint16_t tmp = PC;
    return M->read(tmp+signed(M->read(++PC)));
}
uint8_t M6502_core::read_abs(){                             //read using absolute addressing
    uint8_t temp = M->read(M->readWord(++PC));
    PC++;
    return temp;
}

uint8_t M6502_core::read_abs(uint8_t index){                //read using indexed absolute addressing pass X or Y register
    uint8_t temp = M->read(M->readWord(++PC)+index);
    PC++;
    return temp;
}

uint16_t M6502_core::read_ind(){                            //read using indirect addressing, returns a word
    uint16_t temp = M->readWord(M->readWord(++PC));
    PC++;
    return temp;
}

uint8_t M6502_core::read_ind_x(){                           //read using X-Indexed Indirext addressing
    return M->read(M->readWord(M->read(++PC)+X));
}

uint8_t M6502_core::read_ind_y(){                           //read using Indirect Y-Indexed addressing
    return M->read(M->readWord(M->read(++PC))+Y);
}

/*------------------------------------------------------------------------------------------------*/

void M6502_core::execute(uint8_t val){
    switch (val){

        case instruct::BRK:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            nmi();
            SR.B = 1;
            break;
            
        case instruct::ORA_x_ind:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A |= read_ind_x();
            break;

        case instruct::ORA_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A |= read_zpg();
            break;

        case instruct::ASL_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            M->write(PC,(read_zpg() << 1));
            break;

        case instruct::PHP_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            stack_push(read_SR());
            break;

        case instruct::ORA_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
             A |= M->read(++PC);
            break;

        case instruct::ASL_a:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            SR.C=(A&0x80)>>7;
            A = (A<<1);
            break;

        case instruct::ORA_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A|= read_abs();
            break;

        case instruct::ASL_abs:{
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            uint8_t tmp;
            tmp = read_abs();
            SR.C=(tmp&0x80)>>7;
            M->write(M->readWord(PC+1),tmp<<1);
            }
            break;

        case instruct::BPL_rel:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ORA_ind_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A|= read_ind_y();
            break;

        case instruct::ORA_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A|= read_zpg(X);
            break;

        case instruct::ASL_zpg_x:{
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            uint8_t tmp;
            tmp = read_zpg(X);
            SR.C=(tmp&0x80)>>7;
            M->write(M->readWord(PC+1+X),read_zpg(X) <<1);
            }
            break;

        case instruct::CLC_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ORA_abs_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A|= read_abs(Y);
            break;

        case instruct::ORA_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A|= read_abs(X);
            break;

        case instruct::ASL_abs_x:{
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            uint8_t tmp;
            tmp = read_abs();
            SR.C=(tmp&0x80)>>7;
            M->write(M->readWord(PC+1),tmp << 1);
            }
            break;

        case instruct::JSR_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::AND_x_ind:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A = ((PC+1) & read_ind_x());
            break;

        case instruct::BIT_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::NAD_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ROL_apg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::PLP_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::AND_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A = ((PC+1) & A);
            break;

        case instruct::ROL_a:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::BIT_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::AND_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A = (read_zpg(PC+1) & A);
            break;

        case instruct::ROL_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::BMI_rel:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::AND_ind_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A = ((PC+1) & read_ind_y());
            break;

        case instruct::AND_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A = (read_zpg(PC+1) & X);
            break;

        case instruct::ROL_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SEC_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::AND_abs_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A =((PC+1) &  Y);
            break;

        case instruct::AND_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            A = ((PC+1) & X);
            break;

        case instruct::ROL_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::RTI_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::EOR_x_ind:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::EOR_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LSR_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::PHA_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::EOR_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LAS_a:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::JMP_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::EOR_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LSR_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::BVC_rel:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::EOR_ind_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::EOR_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LSR_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CLI_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::EOR_abs_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::EOR_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LSR_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::RTS_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ADC_x_ind:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ADC_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;


        case instruct::ROR_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::PLA_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ADC_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ROR_a:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::JMP_ind:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ADC_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ROR_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::BVS_rel:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ADC_ind_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ADC_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ROR_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SEI_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ADC_abs_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ADC_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::ROR_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STA_x_ind:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STY_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STA_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STX_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::DEY_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::TXA_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STY_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STA_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STX_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::BCC_rel:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STA_ind_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STY_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STA_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STX_zpg_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::TYA_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STA_abs_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::TXS_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::STA_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDY_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDA_x_ind:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDX_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDY_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDA_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDX_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::TAY_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDA_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::TAX_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDA_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::BCS_rel:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDA_ind_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDY_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDA_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDX_zpg_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CLV_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDA_abs_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::TSX_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDY_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDA_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::LDX_abs_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CPY_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CMP_x_ind:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CPY_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CMP_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::DEC_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::INY_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CMP_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::DEX_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CPY_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CMP_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::DEC_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::BNE_rel:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CMP_ind_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CMP_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::DEC_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CLD_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CMP_abs_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CMP_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::DEC_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CPX_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SBC_x_ind:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CPX_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SBC_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::INC_zpg:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::INX_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SBC_n:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::NOP_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::CPX_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SBC_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::INC_abs:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::BEQ_rel:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SBC_ind_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SBC_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::INC_zpg_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SED_impl:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SBC_abs_y:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::SBC_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::INC_abs_x:
            std::cout << "Valid Code: " << std::hex << std::uppercase << unsigned(val) << std::endl;
            break;

        case instruct::EXT:
            std::cout << "code EXT or 0xFF" << std::endl;
            break;

        default:
            std::cout << "I cant find this code!" << std::endl;
        break;
    }
}

