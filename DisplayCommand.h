#ifndef DISPLAYCOMMAND_H_
#define DISPLAYCOMMAND_H_
#include <string>
#include "Command.h"
using namespace std;

/// @brief display command show the classified result.
class DisplayCommand : public Command
{
    
public:
    /// @brief constructor diplay task.
    /// @param my_dio for connection
    /// @param my_data for data.
    DisplayCommand(DefaultIO *my_dio, Data *my_data);
    
    /// @brief the task excecute.
    void execute() override;
};
#endif