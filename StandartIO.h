#ifndef STANDARTIO_H_
#define STANDARTIO_H_
#include <string>
#include "DefaultIO.h"

using namespace std;


/**
 * class represents communication with standard io.
 */
class StandartIO : public DefaultIO {
public:

    StandartIO();
    
    /**
     * Reads user input and returns it.
     * @return user input
     */
    string read() override;

    /**
     * Writes the given output.
     * @param str output string
     */
    void write(const string &str) override;
};

#endif