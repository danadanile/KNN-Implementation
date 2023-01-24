#ifndef COMMAND_H_
#define COMMAND_H_
#include <string>
#include "DefaultIO.h"
#include "Data.h"
using namespace std;

/// @brief abstruct Command class
class Command {


protected: 
    string description;
    DefaultIO* dio;
    Data* data;

public:
    /// @brief constructor
    Command(DefaultIO *my_dio, Data *my_data);

    /// @brief get the command description 
    string getDescription() const;

    
    /// @brief Execute command.
    virtual void execute() = 0;

    /// @brief Destructor.
    virtual ~Command() = default;
};

#endif