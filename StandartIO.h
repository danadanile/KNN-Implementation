#ifndef STANDARTIO_H_
#define STANDARTIO_H_
#include <string>
#include "DefaultIO.h"

using namespace std;

class StandartIO : public DefaultIO 
 {
    /// @brief abstruct Command class
   
    string read();
    void write(string s);

};
#endif