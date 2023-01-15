#ifndef UPLOADCOMMAND_H_
#define UPLOADCOMMAND_H_
#include <string>
#include "Command.h"
using namespace std;

class UploadCommand : public Command {
    /// @brief Command2 class for gatting k and distance params
    
public: 
   UploadCommand(DefaultIO *dio);
   void execute(Data &data);

};
#endif