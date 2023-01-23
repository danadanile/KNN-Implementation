#ifndef STANDARTIO_H_
#define STANDARTIO_H_
#include <string>
#include "DefaultIO.h"

using namespace std;


 /// @brief class responsible to communicate with standard io.
class StandartIO : public DefaultIO {
public:

    StandartIO();
    
    /// @brief Reads user input.
    /// @return user input
    string read() override;
    

    
    /// @brief write output.
    /// @param str output
    void write(const string &str) override;
};

#endif