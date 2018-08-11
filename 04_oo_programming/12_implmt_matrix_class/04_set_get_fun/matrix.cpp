/*
// empty constructor function syntax
Classname::ClassName() {

    constructor function definition
}

// constructor function syntax
Classname::ClassName(datatype variable1, datatype variable2, …, datatype variablen) {

    constructor function definition

}

*/

#include "matrix.hpp"

/* TODO: Define the default constructor. Remember the syntax is
**      Classname::ClassName() {
**
**          initialize variables
**
**       }
**
**
**      You need to initialize the grid variable to a default value such as
**      a 4x4 matrix with all zeros.
**
**      Then initialize the rows variable, and the cols variable using the
**      vector size method. For example myvector.size() will give the size of
**      a vector. For a 2-dimensional vector, myvector.size() would be the
**      number of rows in a matrix.
**
*/
//default constructor
Matrix::Matrix(){
    //4x4
    std::vector<std::vector<float> > inigrid (4,std::vector<float> (4,0));
    grid = inigrid;
    rows = grid.size();
    cols = grid[0].size();


}
/* TODO: Define the a constructor that receives a 2-Dimensional vector
**       and assigns the vector to the grid variable.
**
**      Remember the syntax is
**      Classname::ClassName(datatype inputvariablename) {
**
**          classvariable = inputvariablename
**
**       }
**
**      Then initialize the rows variable, and the cols variable exactly
**      as you did for the default constructor.
**
*/
Matrix::Matrix(std::vector<std::vector<float> > initial_grid){
    grid = initial_grid;
    rows = grid.size();
    cols = grid[0].size();
}


/* TODO: Declare the setGrid(), getGrid(), getRows(),
**       and getCols() functions.
**
**  Here are the inputs and outputs of each function:
**  setGrid()
**  INPUTS: 2D vector
**  OUPUTS: void
**
**  getGrid()
**  INPUTS: void
**  OUPUTS: 2D vector
**
**  getRows()
**  INPUTS: void
**  OUTPUTS: std::vector<float>::size_type
**
**  getCols()
**  INPUTS: void
**  OUPUTS: std::vector<float>::size_type
*/
void Matrix::setGrid(std::vector<std::vector<float> > input_grid){
    grid = input_grid;
    rows = grid.size();
    cols = grid[0].size();
}

std::vector<std::vector<float> > Matrix::getGrid(){
    return grid;
}

std::vector<float>::size_type Matrix::getRows(){
    return rows;
}

std::vector<float>::size_type Matrix::getCols(){
    return cols;
}







