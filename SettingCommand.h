#ifndef SETTINGCOMMAND_H_
#define SETTINGCOMMAND_H_
#include "Command.h"


/// @brief class shows or change the k and distance matric
class SettingCommand : public Command {
private:
  

public:

    /// @brief Constructor.
    /// @param dio pointer to a DefaultIO object for user io.
    /// @param dataObj
    SettingCommand(DefaultIO* dio, Data* data);


    /// @brief check if k is valid
    bool isValidK(string k_input);

    /// @brief spit input by space and enter to vector.
    /// @param vec vector to inset the input
    /// @param userInput the input
    void getInput(vector<string> &vec, string userInput);

    /// @brief execute command
    void execute() override;
};
#endif