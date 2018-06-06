#include <iostream>
#include <exception>

namespace exception {

    class myException : public std::invalid_argument
    {
    public:
        const char* what()
        {
            return "Invalid argument exception";
        }
    };
};
