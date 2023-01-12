#ifndef COMMAND_H_
#define COMMAND_H_
#include <string>
#include "DefaultIO.h"
using namespace std;

class Command {
    /// @brief abstruct Command class
    string description;
    DefaultIO dio;

public: 
   Command();
   void execute();

};
#endif