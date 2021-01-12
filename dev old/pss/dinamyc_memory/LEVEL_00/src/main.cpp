#include <iostream>

//////////////////////////////////////////////////////////////////////////
///////////////////////////LEVEL_00///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///////////////////THE BASIC OF DIMAMYC MEMORY////////////////////////////
//////////////////////////////////////////////////////////////////////////

// ABC
int abc = 10;               // val(abs) = val(10)

// Reference To Int
int& referenceToInt = abc;  // dir(rti) = dir(abc) 

// Pointer To Int
int* pointerToInt = &abc;   // val(pti) = dir(abc)

// Reference To Pointer
int& referenceToPointer = *pointerToInt; // dir(rtp) = val(pti);

int main(void) {
    std::cout << "ABC: " << abc << std::endl;
    std::cout << "RTI: " << referenceToInt << std::endl;
    std::cout << "PTI: " << pointerToInt << std::endl;
    std::cout << "RTP: " << referenceToPointer << std::endl;
    return 0;
}