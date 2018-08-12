#include <iostream>

int main() {

    // declare integer variables
    int a, b, c, d, e;
    a = 5;
    b = 17;
    c = 2;
    d = 40;
    e = 38;

    // print out the addresses for each variable
    // The ampersand symbol gives access to the address of a variable
    std::cout << "hexadecimal addresses on the stack: \n";
    // use 4 bytes each
    std::cout << &a << "\n";
    std::cout << &b << "\n";
    std::cout << &c << "\n";
    std::cout << &d << "\n";
    std::cout << &e << "\n \n";

    // show the addresses in decimal notation so that they are easier to interpret
    // each variable need 4 bytes, and a with the lower address due to it use stack,
    // declare first, lower in stack, so it has larager address
    std::cout << "same addresses in decimal: \n";
    std::cout << (long int)&a << "\n";
    std::cout << (long int)&b << "\n";
    std::cout << (long int)&c << "\n";
    std::cout << (long int)&d << "\n";
    std::cout << (long int)&e << "\n";


    /*
    The heap, on the other hand, starts with lower number addresses and increases.
    Exactly what addresses get assigned will vary from system to system when the program executes.
    */
    // declare pointers for integer variables
    // each pointer cost 4 bytes in int type
    int * f;
    int * g;
    int * h;
    int * i;
    int * j;

    // use the new operator for dynamic memory allocation
    f = new int;
    g = new int;
    h = new int;
    i = new int;
    j = new int;

    // assign values to the pointers
    *f = 5;
    *g = 17;
    *h = 2;
    *i = 40;
    *j = 38;

    // print out the hexadecimal addresses for these variables
    std::cout << "\n hexadecimal addresses on the heap: \n";
    std::cout << f << "\n";
    std::cout << g << "\n";
    std::cout << h << "\n";
    std::cout << i << "\n";
    std::cout << j << "\n \n";


    // print out the decimal addresses for these variables
    std::cout << "same addresses in decimal: \n";

    std::cout << (long int)f << "\n";
    std::cout << (long int)g << "\n";
    std::cout << (long int)h << "\n";
    std::cout << (long int)i << "\n";
    std::cout << (long int)j << "\n";


    delete f;
    delete g;
    delete h;
    delete i;
    delete j;

    f = NULL;
    g = NULL;
    h = NULL;
    i = NULL;
    j = NULL;

    return 0;
}

/*

hexadecimal addresses on the stack:
0x7ffee6f5aab8
0x7ffee6f5aab4
0x7ffee6f5aab0
0x7ffee6f5aaac
0x7ffee6f5aaa8

same addresses in decimal:
140732773280440
140732773280436
140732773280432
140732773280428
140732773280424

 hexadecimal addresses on the heap:
0x7f87364002e0
0x7f8736400340
0x7f8736400350
0x7f8736402660
0x7f8736402670

same addresses in decimal:
140218707477216
140218707477312
140218707477328
140218707486304
140218707486320


*/