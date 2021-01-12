#include <stddef.h>
#include <iostream>
#include <array>

#define LOG(x) std::cout << x << std::endl;

//////////////////////////////////////////////////////////////////////////
///////////////////////////LEVEL_02///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
///////////////////DYNAMIC ARRAYS DEPRECATED//////////////////////////////
//////////////////////////////////////////////////////////////////////////

class ArrayInt {
private:
    int *ptr = 0;
    uint8_t length = 0;
public:
    ArrayInt() {
        ptr = new int();
    }
    ~ArrayInt() {
        for (uint8_t i = 0; i < length; ++i) {
            delete (ptr + i);
        }
        ptr = 0;
    }

    void push(int element) {
        *(ptr + length) = element;
        length++;
    }

    void push(int index, int element) {
        if (index > length-1 || index < 0) {
            std::cout << " --- index out of bounds --- " << std::endl;
            return;
        }

        int* auxElements = new int();
        for (uint8_t i = 0; i < length; ++i) {
            *(auxElements + i) = *(ptr + i);
        }

        for (uint8_t i = index; i < length; ++i) {
            
            if (i == length - 1) {
                *(ptr + i + 1) = *(auxElements + i);
                *(ptr + index) = element;
                ++length;
                return;
            }
            *(ptr + i + 1) = *(auxElements + i);
        }
    }///[a] [d] [c] [d]
     ///0  1  2  3
    void pop() {
        delete (ptr + length);
        length--;
    }

    void pop(int index) {
        if (index > length-1 || index < 0) {
            std::cout << " --- index out of bounds --- " << std::endl;
            return;
        }

        for (uint8_t i = index; i < length; ++i) {
            if (i == length-1) {
                delete (ptr + i);
                --length;
                return;
            }
          *(ptr + i + 1) = *(ptr + i);  
        }
    }

    void printElements(void) const {
        std::cout << *(ptr + 0);

        for (uint8_t i = 1; i < length; i++) {
            std::cout << ", " << *(ptr + i);
        }
    }
};



int main(void) {
    ArrayInt ai;

    ai.push(1);
    ai.push(2);
    ai.push(3);

    ai.printElements();


    return 0;   
}