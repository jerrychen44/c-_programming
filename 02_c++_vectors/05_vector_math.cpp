#include <iostream>
#include <vector>

using namespace std;

// function declaration
vector<float> vectorsubtraction(vector<float> vector1, vector<float> vector2);
vector<float> multiplicationvector(vector<float> v1, vector<float> v2);

// program that computes the difference between two vectors
/*

Idea 1
First, try writing a program that initializes a vector of size 3.
The values for this vector are [5, 10, 27][5,10,27].
Initialize another vector of size 3 with the values [3, 17, 12][3,17,12].
Now subtract the two vectors from each other and output the results.

To get even more practice, write a function that takes in two vectors
and then outputs the difference between the vectors. Assume that the two vectors are the same size;
otherwise you would have to check that they are the same size and include some error checking.

*/
int idea1() {

    // declare and initialize vectors
    vector<float> v1(3);
    vector<float> v2(3);

    v1[0] = 5.0;
    v1[1] = 10.0;
    v1[2] = 27.0;

    v2[0] = 2.0;
    v2[1] = 17.0;
    v2[2] = 12.0;

    vector<float> v3 (v1.size());

    // calculate the difference between the two vectors
    v3 = vectorsubtraction(v1, v2);

    // print out the results of the vector subtraction
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }

    cout << endl;

    return 0;

}

// define the function -
// INPUTS: two vectors
// OUTPUT: the difference between the two vectors
vector<float> vectorsubtraction(vector<float> vector1, vector<float> vector2) {

    vector<float> vectordifference (vector1.size());

    if(vector1.size() != vector2.size()){
        cout<< "Two vectors size are not the same." <<endl;
        vectordifference.assign(vector1.size(),-99);
        return vectordifference;
    }

    for (int i = 0; i < vector1.size(); i++) {
        vectordifference[i] = vector1[i] - vector2[i];
    }

    return vectordifference;

}



/*
Idea 2
Initialize a vector with the values [17, 10, 31, 5, 7].
Initialize another vector with the values [3, 1, 6, 19, 8].
Then, output another vector that contains the product of each element. In other words, the vector should have
[17\times3, \space10\times1, \space 31\times6, \space 5\times19, \space 7\times8][17×3, 10×1, 31×6, 5×19, 7×8].

To get even more practice, write a function that takes in two vectors and
then outputs a new vector that is the result of element by element multiplication.
Assume that the two vectors are the same size;
otherwise you would have to check that they are the same size and do some error checking.

*/
int idea2(){
    //initialize vector
    vector<float> v1(5);
    v1[0] = 17;
    v1[1] = 10;
    v1[2] = 31;
    v1[3] = 5;
    v1[4] = 7;

    vector<float> v2(5);
    v2[0] = 3;
    v2[1] = 1;
    v2[2] = 6;
    v2[3] = 19;
    v2[4] = 8;

    vector<float> result(v2.size());

    result = multiplicationvector(v1,v2);

    //print result
    for (int i =0; i < result.size(); ++i)
        cout << result[i] << " ";


    return 0;
}

vector<float> multiplicationvector(vector<float> v1, vector<float> v2){

    vector<float> inside_result(v1.size());

    if(v1.size() != v2.size()){
        cout<< "Two vectors size are not the same." <<endl;
        inside_result.assign(v1.size(),-99);
        return inside_result;
    }

    for(int i =0; i < v1.size(); ++i){
        inside_result[i] = v1[i] * v2[i];
    }
    return inside_result;
}





int main(){
    idea1();
    idea2();


}