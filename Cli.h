#ifndef CLI_H_
#define CLI_H_
#include "Command.h"

class Cli
{

private:
    DefaultIO *d_io;
    //vector<Command *> m_commands;

public:
    /// @brief constructor
    /// @param dio default IO
    Cli(DefaultIO *d_io);


    /// @brief start cli run
    void start();

    
    /// @brief Destructor.
    ~Cli();
};

#endif
