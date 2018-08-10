#include <vector>
#include <iostream>
//Namespaces
using namespace std;

int example1() {

    vector<char> charactervectorvariable;
    vector<int> integervectorvariable;
    vector<float> floatvectorvariable;
    vector<double> doublevectorvariable;

    int intvariable = 5;
    cout << intvariable << endl;
    return 0;
}

int example2(){
    string fruit = "apple";
    string vegetable = "broccoli";

    cout << "My favorite fruit is " << fruit <<
    "and my favorite vegetable is " << vegetable << "\n";

    return 0;
}



int main(){
    example1();
    example2();


}