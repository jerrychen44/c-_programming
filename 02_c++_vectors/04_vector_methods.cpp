#include <iostream>
#include <vector>

using namespace std;

int main() {

    // Part 1: declare and define a vector {5.0, 5.0, 5.0} and print it out
    vector<float> vectorvar(3, 5.0);

    for (int i = 0; i < vectorvar.size(); i++) {
        cout << vectorvar[i] << " ";
    }

    cout << endl;

    // Part 2: Use push back to add the values 3.0, 2.5, 1.4 to the back of the vector
    // Pushback adds an element to the end of the vector:
    vectorvar.push_back(666);
    vectorvar.push_back(1.1);


    // Part 3: Print out the vector
    for (int i = 0; i < vectorvar.size(); i++) {
        cout << vectorvar[i] << " ";
    }
    cout << "\n";

    // Part 4: Use the assign method so that the current vector has values
    // {5.0, 5.0, 5.0}
    /*
    Assign is going to populate the vector with ten integers all having the value of 16.
    The assign method lets you override your current vector with a new vector.
    Remember, you've already seen a similar way to initialize values in a vector
    */
    vectorvar.assign(3, 5.0);

    // Part 5: Print out the vector
    for (int i = 0; i < vectorvar.size(); i++) {
        cout << vectorvar[i] << " ";
    }

    cout << "\n";

    return 0;
}