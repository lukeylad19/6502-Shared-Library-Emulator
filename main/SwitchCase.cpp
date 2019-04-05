#include <iostream>
#include <stdint.h>
#include <string>
#include "opcode.h"

using namespace std;
int main( int c, char** argv){

    int val;
    cout << "enter OpCode:" << endl;
    cin >> val;

    switch (val){

        case opCode::BRK:
            cout << "code BRK or 0x00" << endl;
            break;
            
        case opCode::ORA_x_ind:
            cout << "code ORA_x_ind or 0x01" << endl;
            break;

        case opCode::ORA_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::ASL_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::PHP_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::ORA_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::ASL_a:
            cout << "Valid Code" << endl;
            break;

        case opCode::ORA_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::ASL_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::BPL_rel:
            cout << "Valid Code" << endl;
            break;

        case opCode::ORA_ind_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::ORA_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::ASL_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::CLC_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::ORA_abs_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::ORA_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::ASL_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::JSR_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::AND_x_ind:
            cout << "Valid Code" << endl;
            break;

        case opCode::BIT_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::NAD_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::ROL_apg:
            cout << "Valid Code" << endl;
            break;

        case opCode::PLP_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::AND_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::ROL_a:
            cout << "Valid Code" << endl;
            break;

        case opCode::BIT_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::AND_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::ROL_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::BMI_rel:
            cout << "Valid Code" << endl;
            break;

        case opCode::AND_ind_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::AND_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::ROL_zpg_x:
            cout << "Valid Code" << endl;
            break;


        case opCode::SEC_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::AND_abs_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::AND_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::ROL_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::RTI_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::EOR_x_ind:
            cout << "Valid Code" << endl;
            break;

        case opCode::EOR_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::LSR_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::PHA_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::EOR_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::LAS_a:
            cout << "Valid Code" << endl;
            break;

        case opCode::JMP_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::EOR_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::LSR_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::BVC_rel:
            cout << "Valid Code" << endl;
            break;

        case opCode::EOR_ind_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::EOR_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::LSR_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::CLI_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::EOR_abs_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::EOR_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::LSR_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::RTS_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::ADC_x_ind:
            cout << "Valid Code" << endl;
            break;

        case opCode::ADC_zpg:
            cout << "Valid Code" << endl;
            break;


        case opCode::ROR_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::PLA_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::ADC_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::ROR_a:
            cout << "Valid Code" << endl;
            break;

        case opCode::JMP_ind:
            cout << "Valid Code" << endl;
            break;

        case opCode::ADC_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::ROR_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::BVS_rel:
            cout << "Valid Code" << endl;
            break;

        case opCode::ADC_ind_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::ADC_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::ROR_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::SEI_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::ADC_abs_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::ADC_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::ROR_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::STA_x_ind:
            cout << "Valid Code" << endl;
            break;

        case opCode::STY_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::STA_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::STX_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::DEY_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::TXA_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::STY_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::STA_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::STX_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::BCC_rel:
            cout << "Valid Code" << endl;
            break;

        case opCode::STA_ind_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::STY_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::STA_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::STX_zpg_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::TYA_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::STA_abs_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::TXS_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::STA_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDY_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDA_x_ind:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDX_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDY_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDA_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDX_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::TAY_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDA_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::TAX_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDA_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::BCS_rel:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDA_ind_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDY_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDA_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDX_zpg_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::CLV_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDA_abs_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::TSX_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDY_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDA_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::LDX_abs_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::CPY_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::CMP_x_ind:
            cout << "Valid Code" << endl;
            break;

        case opCode::CPY_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::CMP_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::DEC_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::INY_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::CMP_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::DEX_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::CPY_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::CMP_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::DEC_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::BNE_rel:
            cout << "Valid Code" << endl;
            break;

        case opCode::CMP_ind_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::CMP_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::DEC_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::CLD_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::CMP_abs_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::CMP_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::DEC_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::CPX_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::SBC_x_ind:
            cout << "Valid Code" << endl;
            break;

        case opCode::CPX_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::SBC_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::INC_zpg:
            cout << "Valid Code" << endl;
            break;

        case opCode::INX_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::SBC_n:
            cout << "Valid Code" << endl;
            break;

        case opCode::NOP_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::CPX_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::SBC_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::INC_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::BEQ_rel:
            cout << "Valid Code" << endl;
            break;

        case opCode::SBC_ind_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::SBC_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::INC_zpg_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::SED_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::SBC_abs_y:
            cout << "Valid Code" << endl;
            break;

        case opCode::SBC_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::INC_abs_x:
            cout << "Valid Code" << endl;
            break;

        case opCode::EXT:
            cout << "code EXT or 0xFF" << endl;
            break;

        default:
            cout << "I cant find this code!" << endl;
        break;
    }


    return 0;
}
