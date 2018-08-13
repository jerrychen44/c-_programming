#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>

#include "headers/initialize_beliefs.h"
#include "headers/sense.h"
#include "headers/blur.h"
#include "headers/normalize.h"
#include "headers/move.h"
#include "headers/print.h"

using namespace std;

int main() {

	// number of iterations
	int iterations = 10000;

	std::clock_t start;
	double duration;

	//Grid is a char vector holding the color values of a 2-dimensional square grid.
	vector < vector <char> > grid { {'r', 'g', 'r', 'r', 'r'}, {'g', 'r', 'r', 'g', 'r'}, {'r', 'g', 'r', 'r', 'r'} };
	vector< vector <float> > beliefs;

	cout << "number of iterations: " << iterations << " " << "\n";

	// test initialize_beliefs
	//The initialize_beliefs function takes in the char grid
	//and outputs the initial probabilities for each square on the grid.
	start = std::clock();
	for (int i = 0; i < iterations; i++) {
		beliefs = initialize_beliefs(grid);
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "duration milliseconds initialize beliefs " << 1000 * duration << '\n';

	// test sense
	start = std::clock();
	for (int i = 0; i < iterations; i++) {
		beliefs = sense('g', grid, beliefs, .7, .2);
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "duration milliseconds sense " << 1000 * duration << '\n';

	// test blur
	start = std::clock();
	for (int i = 0; i < iterations; i++) {
		beliefs = blur(beliefs, .12);
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "duration milliseconds blur " << 1000 * duration << '\n';

	// test normalize
	start = std::clock();
	for (int i = 0; i < iterations; i++) {
		beliefs = normalize(beliefs);
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "duration milliseconds normalize " << 1000 * duration << '\n';

	// test move
	start = std::clock();
	for (int i = 0; i < iterations; i++) {
		beliefs = move(3, 2, beliefs);
	}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	std::cout << "duration milliseconds move " << 1000 * duration << '\n';

}

/*
number of iterations: 10000
duration milliseconds initialize beliefs 16.301
duration milliseconds sense 17.999
duration milliseconds blur 78.695
duration milliseconds normalize 16.765
duration milliseconds move 23.452


gcc flag -o2

number of iterations: 10000
duration milliseconds initialize beliefs 8.101
duration milliseconds sense 8.652
duration milliseconds blur 32.217
duration milliseconds normalize 6.619
duration milliseconds move 8.528

-o3
number of iterations: 10000
duration milliseconds initialize beliefs 8.482
duration milliseconds sense 8.438
duration milliseconds blur 38.722
duration milliseconds normalize 6.303
duration milliseconds move 8.651


*/