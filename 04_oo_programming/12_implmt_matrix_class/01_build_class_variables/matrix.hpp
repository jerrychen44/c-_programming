/*
class Classname
{
    private:
        declare private variables;
        declare private functions;

    public:
        declare public variables;
        declare public functions;
};



**  TODO:
**    Declare the following private variables:
**      a 2D float vector variable called grid
**      a vector size_type variable called rows
**      a vector size_type variable called cols
*/

#include <vector>


class Matrix{


    private:
        std::vector<std::vector<float> > grid;
        //The rows and columns variables should be declared as a size_type.
        //A size_type variable holds the size of a vector.

        //If your vector holds floats, then the size_type declaration would look like this:
        std::vector<float>::size_type rows;
        std::vector<float>::size_type cols;


        //If your vector holds integers, the size_type declaration looks like this:
        //std::vector<int>::size_type rows;
        //std::vector<int>::size_type cols;

    public:



};