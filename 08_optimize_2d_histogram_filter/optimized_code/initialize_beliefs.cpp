#include "headers/initialize_beliefs.h"

using namespace std;

// OPTIMIZATION: pass large variables by reference
vector< vector <float> > initialize_beliefs(vector< vector <char> > &grid) {

	// OPTIMIZATION: Which of these variables are necessary?
	// OPTIMIZATION: Reserve space in memory for vectors
  	//vector< vector <float> > newGrid;
	//vector<float> newRow;

	//int i, j, height, width, area;
	//float total, prob_per_cell;

	static int height = grid.size();
	static int width = grid[0].size();
	static int area = height * width;

  	static float prob_per_cell = 1.0 / ( (float) area) ;

  	// OPTIMIZATION: Is there a way to get the same results 	// without nested for loops?
  	/*
	for (i=0; i<grid.size(); i++) {
		newRow.clear();
		for (j=0; j<grid[0].size(); j++) {
			newRow.push_back(prob_per_cell);
		}
		newGrid.push_back(newRow);
	}*/
	vector< vector <float> > newGrid (height, vector<float> (width,prob_per_cell));

	return newGrid;
}