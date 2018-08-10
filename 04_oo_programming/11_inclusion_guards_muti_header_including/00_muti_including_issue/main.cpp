#include <iostream>
#include <string>
#include "engine.h"
#include "car.h"

using namespace std;

int main() {

    Engine enginelarge("4L");
    Engine enginesmall("2.5L");

    Car carone("red", 5);
    Car cartwo("green", 4);


    cout << "Small engine size "  << enginesmall.getSize() << endl;
    cout << "Large engine size " << enginelarge.getSize() << endl;
    cout << "Car one doors " << carone.getDoors() << endl;
    cout << "Car two doors " << cartwo.getDoors() << endl;

    cout << "Car one engine size " << carone.getEngine() << endl;
    carone.setEngine(enginelarge.getSize());
    cout << "Car one engine size new " << carone.getEngine() << endl;

    return 0;
}

/*
./engine.h:3:7: error: redefinition of 'Engine'
class Engine
      ^
main.cpp:3:10: note: './engine.h' included multiple times, additional include site here
#include "engine.h"
         ^
./car.h:2:10: note: './engine.h' included multiple times, additional include site here
#include "engine.h"
         ^
./engine.h:3:7: note: unguarded header; consider using #ifdef guards or #pragma once
class Engine
      ^
1 error generated.

*/