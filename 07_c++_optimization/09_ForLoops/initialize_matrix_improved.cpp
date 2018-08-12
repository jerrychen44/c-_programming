#include "initialize_matrix_improved.hpp"

using namespace std;
vector < vector<int> > initialize_matrix_improved(int num_rows, int num_cols, int initial_value) {


    /*
    //method 1 : cost 1335.43
    vector < vector<int> > matrix;
    vector<int> new_row;

    for (int j = 0; j < num_cols; j++) {
        new_row.push_back(initial_value);
    }

    for (int i = 0; i < num_rows; i++) {
        matrix.push_back(new_row);
    }
    return matrix;
    */


    //method 2: 1206.13
    vector < vector<int> > matrix;
    vector<int> new_row(num_cols,initial_value);

    for (int i = 0; i < num_rows; i++) {
        matrix.push_back(new_row);
    }
    return matrix;

}
