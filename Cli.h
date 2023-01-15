#ifndef CLI_H_
#define CLI_H_
#include "Command.h"
#include "Data.h"

class Cli
{

private:
    DefaultIO *d_io;
    Command* commands[5];
    Data data;
    //vector<Command *> m_commands;

public:
    /// @brief constructor
    /// @param dio default IO
    Cli(DefaultIO *d_io);

    /// @brief start cli run
    void start();
    void printMenu();
    bool chooseFromMenu();
    bool checkChooseValid(string choose);


    
    /// @brief Destructor.
    ~Cli();
};

#endif
