/*
thress kinds of func:
    constructor functions
    set and get functions for private variables
    functions for Matrix functionality


**  TODO:
**    Declare the following private variables:
**      a 2D float vector variable called grid
**      a vector size_type variable called rows
**      a vector size_type variable called cols
            ex: printing out the matrix, add , sub, multiplying matrix
*/
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>


class Matrix{


    private:
        std::vector<std::vector<float> > grid;
        //The rows and columns variables should be declared as a size_type.
        //A size_type variable holds the size of a vector.

        //If your vector holds floats, then the size_type declaration would look like this:
        std::vector<float>::size_type rows;
        std::vector<float>::size_type cols;


        //If your vector holds integers, the size_type declaration looks like this:
        //std::vector<int>::size_type rows;
        //std::vector<int>::size_type cols;

    public:

        /*
        ** TODO: Declare  constructor functions
        ** For the matrix class, you will need two constructor functions.
        ** 1. An empty constructor function
        ** 2. A constructor function that accepts a 2-dimensional vector
        */

        // 2 constructor function declarations
        Matrix ();
        Matrix (std::vector< std::vector<float> >);//overloading

        /*
        ** TODO: Declare set and get functions for the three private variables.
        ** You will need 1 set function and 3 get functions.
        ** The names of these functions should be setGrid, getGrid, getRows,
        ** and getCols.
        **
        ** The setGrid does not return anything and has a 2-D vector input
        ** getGrid returns a 2-D vector and has no input
        ** getRows returns a size_type and has no input
        ** get Cols returns a size_type and has no input
        */
        void setGrid(std::vector< std::vector<float> >);
        std::vector<std::vector<float> > getGrid();
        std::vector<float>::size_type getRows();
        std::vector<float>::size_type getCols();


        /*
        ** TODO: Declare the matrix functions. In a following exercise, you
        ** will program matrix_transpose, matrix_addition and matrix_print
        ** functions. So you will need to declare these two functions.
        **
        ** matrix_transpose has no input and outputs a 2D vector
        ** matrix_addition receives a Matrix and outputs a 2D vector
        ** matrix_print has no inputs and no outputs
        */
        Matrix matrix_transpose();
        Matrix matrix_addition(Matrix);
        void matrix_print();

};
#endif/* MATRIX_H */