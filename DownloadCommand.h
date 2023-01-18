#ifndef DOWNLOADCOMMAND_H_
#define DOWNLOADCOMMAND_H_
#include <string>
#include "Command.h"
using namespace std;

/// @brief display command show train file by classified.

class DownloadCommand : public Command
{
    
public:
    DownloadCommand(DefaultIO *my_dio, Data *my_data);
    void execute() override;
};
#endif