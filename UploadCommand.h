#ifndef UPLOADCOMMAND_H_
#define UPLOADCOMMAND_H_
#include <string>
#include "Command.h"
using namespace std;

class UploadCommand : public Command {
    /// @brief Command2 class for gatting k and distance params
    
public: 
    UploadCommand(DefaultIO *dio, Data *data);
    void execute()override;
    virtual ~UploadCommand();

};
#endif