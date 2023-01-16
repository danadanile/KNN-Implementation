#ifndef CLASSIFYCOMMAND_H_
#define CLASSIFYCOMMAND_H_
#include "Command.h"


/// @brief class classify files with knn
class ClassifyCommand : public Command {
private:
  

public:

    /// @brief Constructor.
    /// @param dio pointer to a DefaultIO object for user io.
    /// @param dataObj
    ClassifyCommand(DefaultIO* dio, Data* data);

    /// @brief execute command
    void execute() override;
};
#endif