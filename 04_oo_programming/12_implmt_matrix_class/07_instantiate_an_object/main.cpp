#include <iostream>
#include "matrix.hpp"

/*

//Instantiate an Object
    Classname objectname(inputs for initializing an object of Classname);

//Then you can access any public variables like:
    objectname.variablename
//And you can access your public functions with:
    objectname.methodname(inputs)

//private variables or functions will not be available to your program.
//That was why you wrote the public get and set functions for your private variables.

*/

int main() {


    // assign a 7x5 matrix to the variable initial_grid
    // all values in the matrix are 0.4
    std::vector <std:: vector <float> > initial_grid (7, std::vector <float>(5, 0.4));

    // TODO: Use the initial grid variable to instantiate a matrix object
    // The matrix object should be called matrixa
    Matrix matrixa = Matrix(initial_grid);

    // TODO: Use the matrix_print() method to print out matrixa
    matrixa.matrix_print();
    // TODO: Print out the number of rows in matrixa. You will need
    // to use the getRows() function and std::cout
    // TODO: Print out the number of columns in matrixa

    std::cout <<  "dim: " << matrixa.getRows() << "x" << matrixa.getCols() << std::endl;


    // TODO: Take the transpose of matrixa and store the results in
    // a variable called transposea
    Matrix matrixa_t = matrixa.matrix_transpose();
    // TODO: Print out transposea
    matrixa_t.matrix_print();
    std::cout <<  "dim: " << matrixa_t.getRows() << "x" << matrixa_t.getCols() << std::endl;


    // Now you will use another 7x5 matrix called matrixb to
    // give the results of the matrix_addition function

    // 7x5 2-dimensional vector with values 0.2
    std::vector <std:: vector <float> > second_grid (7, std::vector <float>(5, 0.2));

    // TODO: Instantiate an object called matrixb. Use the second_grid
    // variable as the input to initialize matrixb
    Matrix matrixb = Matrix(second_grid);

    // TOOD: Add matrixa and matrixb. Store the results in a new matrix
    // variable called matrixsum
    Matrix matrixsum = matrixa.matrix_addition(matrixb);

    // TODO: Print out the matrix contained in the matrixsum variable
    matrixsum.matrix_print();
    std::cout <<  "dim: " << matrixsum.getRows() << "x" << matrixsum.getCols() << std::endl;

    return 0;
}

