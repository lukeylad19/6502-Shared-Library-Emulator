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

        case opCode:ORA_n::
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

        case opCode::AND_#:
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

        case opCode::EOR_#:
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

        case opCode::LSR_abs:
            cout << "Valid Code" << endl;
            break;

        case opCode::RTS_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::ADC_x_impl:
            cout << "Valid Code" << endl;
            break;

        case opCode::ADC_zpg:
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