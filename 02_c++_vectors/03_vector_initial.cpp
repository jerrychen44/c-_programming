
//Python Lists vs. C++ Vectors

#include <vector>
#include <iostream>
//Namespaces
using namespace std;

int example1() {

    vector<float> v1(3);
    v1[0] = 4.5;
    v1[1] = 0.6;
    v1[2] = 2.0;

    for(int i =0; i < v1.size() ; i ++){
        cout<< v1[i] <<"\n";
    }


    return 0;
}

int example2(){
    //C++11 or C++17
    //vector<float> v2 = {99.1, 45.2};
    //older C++
    // initial a vector v2 with 3 elemnet and each elemenet value is 6
    vector<float> v2 (3, 6);

    for(int i =0; i < v2.size() ; i ++){
        cout<< v2[i] <<"\n";
    }

    return 0;
}



int main(){
    example1();
    example2();


}