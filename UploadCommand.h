#ifndef UPLOADCOMMAND_H_
#define UPLOADCOMMAND_H_
#include <string>
#include "Command.h"
using namespace std;

/// @brief Command1 class for getting test and train files

class UploadCommand : public Command
{
    
public:
    UploadCommand(DefaultIO *my_dio, Data *my_data);
    void execute() override;
    
};
#endif