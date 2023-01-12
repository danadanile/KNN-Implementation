#ifndef COMMAND_H_
#define COMMAND_H_
#include <string>
#include "DefaultIO.h"
using namespace std;

class Command {
    /// @brief abstruct Command class
    

public: 
    string description;
    DefaultIO dio;
   Command();
   void execute();

};
#endif