#ifndef COMMAND_H_
#define COMMAND_H_
#include <string>
#include "DefaultIO.h"
using namespace std;

class Command {
    /// @brief abstruct Command class

protected: 
    string description;
    DefaultIO* m_dio;

public:
   /// @brief constructor
   Command();

    /// @brief get the command description 
    string getDescription() const;

    
    /// @brief Execute command.
    virtual void execute() = 0;

    /// @brief Destructor.
    virtual ~Command() = default;
};

#endif