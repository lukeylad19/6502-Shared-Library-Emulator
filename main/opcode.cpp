#include <iostream>
#include "opcode.h"

void printname(){

    string name = "Lukas";
    { 
       std::cout << "Name is: " << name; 
    }
}

printname(); 
