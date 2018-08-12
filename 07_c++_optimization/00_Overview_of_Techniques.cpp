

//profiling code

#include <ctime>

std::clock_t start;
double duration;

start = std::clock();

function_name(var1, var2);

duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

std::cout << "duration milliseconds initialize beliefs " << 1000 * duration << '\n';


//Overview of Techniques

1.Remove Dead Code
2.Avoid Extra if Statements
3.Avoid Nested for Loops
4.Avoid Creating Extra Variables
5.Reserve Space in Memory for Vectors at the first beginning
6.Passing Variables by Reference
7.Using Static

