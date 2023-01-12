#ifndef COMMAND2_H_
#define COMMAND2_H_
#include <string>
#include "Command.h"
using namespace std;

class Command2 : public Command {
    /// @brief Command2 class for gatting k and distance params
    
public: 
   Command2(string description, DefaultIO dio);
   void execute();

};
#endif