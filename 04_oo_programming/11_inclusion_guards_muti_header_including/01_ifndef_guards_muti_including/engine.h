#ifndef ENGINE_H
#define ENGINE_H

#include <string>
/*
It's generally recommended to avoid using namespaces in a header file.
This can help avoid naming conflicts later as functions and classes are reused in different parts of a code base.

*/
class Engine
{
    private:
        std::string enginesize;

    public:

        Engine ();

        Engine (std::string);

        void setSize(std::string);

        std::string getSize();

};
#endif /* ENGINE_H */