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
            cout << "code ORA_zpg or 0x05" << endl;
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