#include <iostream>
#include "vector"


using namespace std;


int example1(){

    //initial a 2d vector, which element are also a vecotr with int type
    vector < vector <int> > twodvector;

    //inital a 1d vector as usual
    vector<int> singlerow (3,2);

    //add the value to 2d vector
    for (int i = 0; i < 5; i++) {
        twodvector.push_back(singlerow);
    }

    //print result
    for(int i =0; i < twodvector.size(); ++i){
        for (int j = 0 ; j < twodvector[0].size(); ++j){
            cout <<twodvector[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;

}


int example2(){
    //declare 5 vector element which has vector [2,2,2] in each one.
    vector < vector <int> > twodvector (5, vector <int> (3, 6));


    //print result
    for(int i =0; i < twodvector.size(); ++i){
        for (int j = 0 ; j < twodvector[0].size(); ++j){
            cout <<twodvector[i][j] << " ";
        }
        cout<<endl;
    }

    //the same as above, for C++11 or 17
    /*
    vector < vector <int> > twodvector2 (5, {2, 2, 2});
    //print result
    for(int i =0; i < twodvector2.size(); ++i){
        for (int j = 0 ; j < twodvector2[0].size(); ++j){
            cout <<twodvector2[i][j] << " ";
        }
        cout<<endl;
    }
    */



    return 0;

}



int main(){

    example1();
    cout<<endl;
    example2();
    return 0;

}