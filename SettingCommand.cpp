#include "SettingCommand.h"
#include "CheckFuncs.h"
#include <vector>
#include <sstream>
using namespace std;

SettingCommand::SettingCommand(DefaultIO *dio, Data *data) : Command(dio, data)
{
    description = "2. algorithm settings";
}

/// @brief insert to vec the input from userInput
/// @param vec
/// @param userInput
void SettingCommand::getInput(vector<string> &vec, string userInput)
{
    string token;
    stringstream X(userInput);
    while (getline(X, token, ' '))
    {
        string param = token;
        vec.push_back(param);
    }
}

bool SettingCommand::isValidK(string k_input){

    if (CheckFuncs::isNumeric(k_input))
    {
        int k = stoi(k_input);
        if (k <= 0)
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}

void SettingCommand::execute(){
    //Send the current setting:
    string message;
    dio->write(string("The current KNN parameters are:") + string(" K = ") + to_string(data->getK()) + ", distance metric = " + data->getDisName() + "\n");
    message.clear();

    //Read the new settings:
    message = dio->read();

    //Enter clicked:
    if (message == "continue"){
        return;
    }

    //New K and Distance-Enter to vector:
    vector<string> vec;
    getInput(vec, message);

    // If not 2 arg:
    if (vec.size() != 2){
        dio->write("invalid value for k\ninvalid value for metric\n");
        return;
    }

    // Validation K:
    bool invalidK = false;
    bool validK = isValidK(vec[0]);
    int k;
    if (validK){
        k = stoi(vec[0]);    
    }
    else{
        invalidK = true;
    }

    // Validation K length:
    if (data->getTestIsInit()){
        if(data->getTest()->getSizeMap()<data->getK()){
            invalidK = true;       
        }
    }

    if (data->getTrainIsInit()){
        if(data->getTrain()->getSizeMap()<data->getK()){
            invalidK = true;       
        }
    }


    // Validation Distance:
    string disName = vec[1];
    int disNum = 0;
    if (disName != "AUC" && disName != "MAN" && disName != "CHB" && disName != "CAN" && disName != "MIN")
    {
        //k also unvalid:
        if (invalidK){
            dio->write("invalid value for k\ninvalid value for metric\n");
            return;
        }
        else{
            dio->write("invalid value for metric\n");
            return;
        }
    }
    else{
        if(invalidK){
            dio->write("invalid value for k\n");
            return;
        }
    }

    //k and disName valid args:
    enum Choise
    {
        AUC = 1,
        MAN = 2,
        CHB = 3,
        CAN = 4,
        MIN = 5
    };

    // convert enums to number
    static map<string, Choise> const table = {{"AUC", Choise::AUC}, {"MIN", Choise::MIN}, {"MAN", Choise::MAN}, {"CHB", Choise::CHB}, {"CAN", Choise::CAN}};
    auto it = table.find(disName);
    if (it != table.end())
    {
        disNum = it->second;
    }
    dio->write("valid\n");
    data->setDisName(disName);
    data->setDisType(disNum);
    data->setK(k);
    return;
}