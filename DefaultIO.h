#ifndef DEFAULTIO_H_
#define DEFAULTIO_H_

#include <string>
using namespace std;

class DefaultIO {
   
public:
    /**
     * Reads user input and return it.
     * @return  user input
     */
    virtual string read() = 0;

    /**
     * Writes the given output.
     * @param str output to write
     */
    virtual void write(const string &str) = 0;

    /**
     * Destructor.
     */
     virtual ~DefaultIO() = default;

};
#endif