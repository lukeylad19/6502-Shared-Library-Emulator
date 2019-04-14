#include <iostream>
#include "instruction.h"
#include "M6502.h"
//#include "opcode.h"
//void execute(uint8_t);
/*int main( int c, char** argv){

  //  opcode op = opcode();
    uint8_t test = 10111000;
   // int val;
   // std::cout << "enter OpCode:" << std::endl;
   // std::cin >> val;

    execute(test);

    return 0;
}*/
void execute(uint8_t val){
    switch (val){

        case instruct::BRK:
            std::cout << "code BRK or 0x00" << std::endl;
            break;
            
        case instruct::ORA_x_ind:
            std::cout << "code ORA_x_ind or 0x01" << std::endl;
            break;

        case instruct::ORA_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ASL_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::PHP_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ORA_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ASL_a:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ORA_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ASL_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::BPL_rel:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ORA_ind_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ORA_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ASL_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CLC_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ORA_abs_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ORA_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ASL_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::JSR_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::AND_x_ind:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::BIT_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::NAD_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ROL_apg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::PLP_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::AND_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ROL_a:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::BIT_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::AND_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ROL_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::BMI_rel:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::AND_ind_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::AND_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ROL_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SEC_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::AND_abs_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::AND_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ROL_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::RTI_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::EOR_x_ind:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::EOR_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LSR_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::PHA_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::EOR_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LAS_a:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::JMP_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::EOR_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LSR_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::BVC_rel:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::EOR_ind_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::EOR_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LSR_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CLI_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::EOR_abs_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::EOR_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LSR_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::RTS_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ADC_x_ind:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ADC_zpg:
            std::cout << "Valid Code" << std::endl;
            break;


        case instruct::ROR_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::PLA_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ADC_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ROR_a:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::JMP_ind:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ADC_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ROR_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::BVS_rel:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ADC_ind_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ADC_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ROR_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SEI_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ADC_abs_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ADC_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::ROR_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STA_x_ind:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STY_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STA_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STX_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::DEY_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::TXA_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STY_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STA_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STX_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::BCC_rel:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STA_ind_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STY_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STA_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STX_zpg_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::TYA_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STA_abs_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::TXS_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::STA_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDY_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDA_x_ind:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDX_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDY_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDA_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDX_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::TAY_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDA_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::TAX_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDA_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::BCS_rel:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDA_ind_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDY_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDA_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDX_zpg_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CLV_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDA_abs_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::TSX_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDY_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDA_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::LDX_abs_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CPY_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CMP_x_ind:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CPY_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CMP_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::DEC_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::INY_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CMP_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::DEX_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CPY_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CMP_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::DEC_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::BNE_rel:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CMP_ind_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CMP_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::DEC_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CLD_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CMP_abs_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CMP_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::DEC_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CPX_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SBC_x_ind:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CPX_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SBC_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::INC_zpg:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::INX_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SBC_n:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::NOP_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::CPX_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SBC_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::INC_abs:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::BEQ_rel:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SBC_ind_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SBC_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::INC_zpg_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SED_impl:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SBC_abs_y:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::SBC_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::INC_abs_x:
            std::cout << "Valid Code" << std::endl;
            break;

        case instruct::EXT:
            std::cout << "code EXT or 0xFF" << std::endl;
            break;

        default:
            std::cout << "I cant find this code!" << std::endl;
        break;
    }
}

