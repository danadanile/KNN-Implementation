#ifndef UPLOADCOMMAND_H_
#define UPLOADCOMMAND_H_
#include <string>
#include "Command.h"
using namespace std;


/// @brief cammand upload task one.
class UploadCommand : public Command
{
    
public:
    /// @brief upload command class task 1:
    /// @param my_dio to read and write.
    /// @param my_data for data.
    UploadCommand(DefaultIO *my_dio, Data *my_data);

    /// @brief function start task 1.
    void execute() override;
    
};
#endif