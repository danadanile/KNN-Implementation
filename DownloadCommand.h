#ifndef DOWNLOADCOMMAND_H_
#define DOWNLOADCOMMAND_H_
#include <string>
#include "Command.h"
using namespace std;

/// @brief download command show train file by classified.
class DownloadCommand : public Command
{
    
public:
    /// @brief download dile
    /// @param my_dio for connection
    /// @param my_data for data.
    DownloadCommand(DefaultIO *my_dio, Data *my_data);
    void execute() override;
};
#endif