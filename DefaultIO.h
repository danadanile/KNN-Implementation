#ifndef DEFAULTIO_H_
#define DEFAULTIO_H_

#include <string>
using namespace std;

class DefaultIO {
   
public:

    /// @brief Reads user input and return it.
    /// @return user input
    virtual string read() = 0;


    /// @brief Writes given output.
    /// @param str output
    virtual void write(const string &str) = 0;

    /// @brief destructor.
    virtual ~DefaultIO() = default;

};
#endif



