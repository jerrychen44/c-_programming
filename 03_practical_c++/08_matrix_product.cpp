#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void print_2dmatrix(vector<vector<float> > inmatrix){

    for(int i =0; i< inmatrix.size();++i){
        for(int j =0; j < inmatrix[0].size();++j){
            cout << inmatrix[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;

}

vector<vector<float> > matrix_product(vector<vector<float> > m1, vector<vector<float> > m2){

    //m1 = mxn
    //m2 = wxz

    int m = m1.size();
    int n = m1[0].size();

    int w = m2.size();
    int z = m2[0].size();

    vector<vector<float> > result(m,vector<float>(z,-99));

    if ( n != w){
        cout << "matrx 1 and matrx 2 can't product together due to wrong dim!" << endl;
        return result;
    }

    //dot product
    float tmp = 0.0;

    for(int i =0; i< m;++i){
        for(int k =0; k < z;++k){
            tmp = 0.0;
            for(int j =0; j < n;++j){
                tmp = tmp + m1[i][j] * m2[j][k];
            }

            result[i][k] = tmp;

        }
    }

    return result;
}


int main() {

    vector<vector<float> > m1(2,vector<float>(5,0.5));
    print_2dmatrix(m1);

    vector<vector<float> > m2(5,vector<float>(3,2));
    print_2dmatrix(m2);

    vector<vector<float> > result(m1.size(),vector<float>(m2[0].size(),0));

    result = matrix_product(m1,m2);
    print_2dmatrix(result);

    return 0;
}