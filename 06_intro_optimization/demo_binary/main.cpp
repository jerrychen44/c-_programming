#include <iostream>
#include <bitset>
#include <cstring>
/*
C++ stores all variables in multiples of bytes:

char is 1 byte
16-bit integer would be 2 bytes
32-bit integer would be 4 bytes -> normal int
32-bit float would be 4 bytes
*/

/*

You can't initialize a bitset at runtime; that's why it's a template argument, or compile-time constant

sizeof(int) * 8 -> simply change bytes to bits
4 * 8 is 32 bits, because bitset accept the bits number as its initial input.
*/
int main() {

    std::cout << "Representations of the number 97 \n";

  	// Character 'a' represented in binary
    std::cout << "\n char: \n" << std::bitset<8>('a') << "\n";

  	// Integer 97 represented with 8 bits
    std::cout << "\n sizeof(char): " << sizeof(char);
    std::cout << "\n 8-bit integer: \n" << std::bitset<sizeof(char) * 8>(97) << "\n";

  // Integer 97 represented with 32 bits
    std::cout << "\n sizeof(int): " << sizeof(int);
    std::cout << "\n 32-bit: \n" << std::bitset<sizeof(int) * 8>(97) << "\n";

  // Float 97.0 represented with 32 bits
    float example = 97.0;
    std::cout << "\n sizeof(float): " << sizeof(float);

    char binary[sizeof(float)];

    memcpy(binary, &example, sizeof(float));

    std::cout << "\n 32-bit float 97.0:  " << "\n";

    for (int i = 0; i < sizeof(float); ++i) {
        std::cout << std::bitset<sizeof(char)*8 >(binary[i]);
    }

    std::cout << "\n";

    return 0;
}
/*
Representations of the number 97

 char:
01100001

 8-bit integer:
01100001

 32-bit:
00000000000000000000000001100001

 32-bit float 97.0:
00000000000000001100001001000010

*/