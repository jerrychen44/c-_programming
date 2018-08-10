#include <iostream>

// class declaration
//one important difference between C++ and Python. In C++,
//you need to declare your class before you can use the class.
//you can put the class declaration into a separate .h file
class Gaussian
{
    private:
        float mu, sigma2;

    public:

        // constructor functions
        Gaussian ();
        Gaussian (float, float);

        // change value of average and standard deviation
        void setMu(float);
        void setSigma2(float);

        // output value of average and standard deviation
        float getMu();
        float getSigma2();

        // functions to evaluate
        float evaluate (float);
        Gaussian mul (Gaussian);
        Gaussian add (Gaussian);
};

int main ()
{
    //get the instance
    Gaussian mygaussian(30.0,100.0);
    Gaussian othergaussian(10.0,25.0);

    std::cout << "average " << mygaussian.getMu() << std::endl;
    std::cout << "evaluation " << mygaussian.evaluate(15.0) << std::endl;

    std::cout << "mul results variance " << mygaussian.mul(othergaussian).getSigma2() << std::endl;
    std::cout << "mul results average " << mygaussian.mul(othergaussian).getMu() << std::endl;

    std::cout << "add results variance " << mygaussian.add(othergaussian).getSigma2() << std::endl;
    std::cout << "add results average " << mygaussian.add(othergaussian).getMu() << std::endl;

    return 0;
}

/*
average 30
evaluation 0.0700165
mul results variance 20
mul results average 14
add results variance 125
add results average 40

*/