#include "headers/blur.h"
#include "headers/zeros.h"
using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {

	// OPTIMIZATION: window, DX and  DY variables have the
    // same value each time the function is run.
  	// It's very inefficient to recalculate the vectors
    // every time the function runs.
    //
    // The const and/or static operator could be useful.
  	// Define and declare window, DX, and DY using the
    // bracket syntax: vector<int> foo = {1, 2, 3, 4}
    // instead of calculating these vectors with for loops
    // and push back
  	//vector < vector <float> > window;
	vector < vector <float> > newGrid;
	//vector <float> row;
	//vector <float> newRow;

    // calculate blur factors
    static float blurring_improved = .12;
    static float center_improved = 1.0 - blurring_improved;
    static float corner_improved = blurring_improved / 12.0;
    static float adjacent_improved = blurring_improved / 6.0;

    //create the blur window
    static vector< vector<float> > window = {
        {corner_improved, adjacent_improved, corner_improved},
        {adjacent_improved, center_improved, adjacent_improved},
        {corner_improved, adjacent_improved, corner_improved}
    };


	static vector <int> DX = {-1,0,1};
	static vector <int> DY = {-1,0,1};

	//DX.push_back(-1); DX.push_back(0); DX.push_back(1);
	//DY.push_back(-1); DY.push_back(0); DY.push_back(1);
	static int i;
	static int j;
	static int dx;
	static int dy;
	static int ii;
	static int jj;
	static int new_i;
	static int new_j;
	static float multiplier;
	static float newVal;

	static int height = grid.size();
	static int width = grid[0].size();

	// OPTIMIZATION: Use your improved zeros function
	/*
	for (i=0; i<height; i++) {
		newRow.clear();
		for (j=0; j<width; j++) {
			newRow.push_back(0.0);
		}
		newGrid.push_back(newRow);
	}*/

	newGrid = zeros(height, width);

	for (i=0; i< height; i++ ) {
		for (j=0; j<width; j++ ) {
			//val = grid[i][j];
			newVal = grid[i][j];
			for (ii=0; ii<3; ii++) {
				dy = DY[ii];
				for (jj=0; jj<3; jj++) {
					dx = DX[jj];
					new_i = (i + dy + height) % height;
					new_j = (j + dx + width) % width;
					//multiplier = window[ii][jj];
					newGrid[new_i][new_j] += newVal * window[ii][jj];
				}
			}
		}
	}

	return newGrid;
}
