#include <iostream>

float distance(float velocity, float acceleration, float time_elapsed);

int main() {

    std::cout << distance(3, 4, 5) << std::endl;
    std::cout << distance(7.0, 2.1, 5.4) << std::endl;

    return 0;
}

//build cmd: g++ 04_structuring_functions_and_file_organization_main.cpp 04_structuring_functions_and_file_organization_distance.cpp