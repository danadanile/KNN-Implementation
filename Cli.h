#ifndef CLI_H_
#define CLI_H_
#include "Command.h"
#include "Data.h"

class Cli {
private:
    DefaultIO* dio;
    Data* data;
    vector<Command*> commands;

public:
   
    /// @brief constructor
    /// @param dio  default IO the commands use
    Cli(DefaultIO* dio);

    /// @brief start cli
    void start();

    
    /// @brief destructor
    ~Cli();
};
#endif