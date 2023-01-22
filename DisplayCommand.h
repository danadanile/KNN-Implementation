#ifndef DISPLAYCOMMAND_H_
#define DISPLAYCOMMAND_H_
#include <string>
#include "Command.h"
using namespace std;

/// @brief display command show the classified result.

class DisplayCommand : public Command
{
    
public:
    DisplayCommand(DefaultIO *my_dio, Data *my_data);
    void execute() override;
};
#endif