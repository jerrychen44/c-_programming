#include "reserved.hpp"

using namespace std;

vector< vector<int> > reserved(int rows, int cols, int initial_value) {

    // OPTIMIZE: use the reserve method with the matrix and new_row variables
    vector< vector<int> > matrix;
    vector<int> new_row;
    new_row.reserve(cols);
    matrix.reserve(rows);

    //one of option is to add below code
    //for(vector < vector<int> >::iterator it=matrix.begin(); it!=matrix.end(); ++it) {
    //    it->reserve(cols);
    //}


    for (int i = 0; i < rows; i++) {
        new_row.clear();
        for (int j = 0; j < cols; j++) {
            new_row.push_back(initial_value);
        }
        matrix.push_back(new_row);
    }

    return matrix;
}
