#include <iostream>
#include <fstream>//fstream provides functions and classes for reading in and outputting files.
#include <string>
#include <sstream>//provides functionality for manipulating and parsing the string
#include <vector>

using namespace std;

int main() {

    // initialize string variables for reading in text file lines
    string line;
    stringstream ss;

    // initialize variables to hold the matrix
    vector < vector <float> > matrix;//2d
    vector<float> row;

    // counter for characters in a text file line
    float i;

    // read in the file
    ifstream matrixfile ("06_matrix");

    // read in the matrix file line by line
    // parse the file

    if (matrixfile.is_open()) {
        while (getline (matrixfile, line)) {//reads the file one line at a time

            // parse the text line with a stringstream
            // clear the string stream to hold the next line
            ss.clear();
            ss.str("");
            ss.str(line);
            row.clear();

            // parse each line and push to the end of the row vector
            while(ss >> i) {
                row.push_back(i);
                // ss.peek looks at the next character to see if it is a comma or a space and ignores commas or spaces.
                if (ss.peek() == ',' ||  ss.peek() == ' ') {
                    ss.ignore();
                }
            }

            // push the row to the end of the matrix
            matrix.push_back(row);
        }

        matrixfile.close();

        // print out the matrix
        for (int row = 0; row < matrix.size(); row++) {
            for (int column = 0; column < matrix[row].size(); column++) {
                cout << matrix[row][column] << " " ;
            }
            cout << endl;
        }
    }

    else cout << "Unable to open file";

    return 0;
}
