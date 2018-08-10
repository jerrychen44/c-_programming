#include <iostream>
#include <vector>

using namespace std;

/*
Practice coding matrices in C++. In this exercise, write a function that has two integer
matrices as inputs and then outputs the sum. Assume that the two input matrices have the same size
(e.g. matrix one is 5x3 and matrix two is 5x3).

*/
//vector < vector <int> > matrix_sum_helper(vector < vector <int> > matrix1, vector < vector <int> > matrix2) {
vector<vector<int> > matrix_sum_helper(vector< vector<int> > matrix1,vector< vector<int> > matrix2){

    //vector<vector<int> > result (5,vector<int> (3,0));
    vector < vector <int> > result (matrix1.size(), vector <int> (matrix1[0].size(), 0));

    for (int i =0; i < result.size(); ++i)
        for( int j=0; j < result[0].size(); ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j];

    return result;
}

int main(){

    //declare 2 matrix
    vector<vector<int> > matrix1 (5,vector<int> (3,2));
    vector<vector<int> > matrix2 (5,vector<int> (3,26));

    vector<vector<int> > result (5,vector<int> (3,0));

    result = matrix_sum_helper(matrix1,matrix2);

    for (int i =0; i < result.size(); ++i){
        for( int j=0; j < result[0].size(); ++j)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}