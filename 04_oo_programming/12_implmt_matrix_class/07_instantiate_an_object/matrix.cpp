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
#include <iostream>
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


/* TODO: Define a matrix_addition function
**   INPUT: a matrix
**   OUPUT: the sum of the grid variable and the input matrix
**
** STEPS:
**  1. check that the matrix in the grid variable
**     and the input matrix have the same size
**
**     if not, throw an error like
**         throw std::invalid_argument("matrices are not the same size");
**
** 2. add the matrices together and return
**       the result as a Matrix. You can do this part
**       with nested for loops. If you use an intermediate
**       vector to store a row, the vector.clear()
**       method might be useful.
**
*/

/* TODO: Define a matrix_print function
** This function has no inputs and no outputs
** The purpose of the function is to display the matrix in
** the terminal using std::cout.
**
**
** The output should look something like:
** 4    9   1   10
** 5    11  6   17
** 8    4   15  2
*/

/*
method1
Matrix Matrix::matrix_addition(Matrix other) {

    if ((rows != other.getRows()) || (cols != other.getCols())) {
        throw std::invalid_argument( "matrices are not the same size" );
    }

    std::vector< std::vector<float> > othergrid = other.getGrid();

    std::vector< std::vector<float> > result;

    std::vector<float> new_row;

    for (int i = 0; i < rows; i++) {
        new_row.clear();
        for (int j = 0; j < cols; j++) {
            new_row.push_back(grid[i][j] + othergrid[i][j]);
        }
        result.push_back(new_row);
    }

    return Matrix(result);
}

*/


Matrix Matrix::matrix_addition(Matrix m_in){

    //check
    if(rows != m_in.getRows() || cols !=m_in.getCols()){
        std::cout << "dimenstion of two matrix doesn't the same!!" << std::endl;
        throw std::invalid_argument("dimenstion of two matrix doesn't the same!!");
    }

    std::vector<std::vector<float> > grid_in = m_in.getGrid();
    std::vector<std::vector<float> > result (rows,std::vector<float> (cols,0.0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = grid[i][j] + grid_in[i][j];
        }
    }

    m_in.setGrid(result);
    return m_in;
}

void Matrix::matrix_print() {

    std::cout << std::endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
/*
Matrix Matrix::matrix_transpose() {
    std::vector< std::vector<float> > new_grid;
    std::vector<float> row;

    for (int i = 0; i < cols; i++) {
        row.clear();

        for (int j = 0; j < rows; j++) {
            row.push_back(grid[j][i]);
        }
        new_grid.push_back(row);
    }

    return Matrix(new_grid);
}
*/

Matrix Matrix::matrix_transpose() {


    std::vector< std::vector<float> > result (cols,std::vector<float>(rows,0.0));
    //std::vector< std::vector<float> > grid = getGrid();

    for(int i=0; i < rows; ++i){
        for(int j=0 ; j < cols; ++j){
            result[j][i] = grid[i][j];
        }
    }

    return Matrix(result);

}
