#include "SettingCommand.h"
#include "CheckFuncs.h"
#include <vector>
using namespace std;

SettingCommand::SettingCommand(DefaultIO* dio, Data* data) : Command(dio, data) {
    description = "2. algorithm settings";
}

bool SettingCommand::isValidK(string k_input) {
    
    if(CheckFuncs::isNumeric(k_input)) {
        int k = stoi(k_input);
        if(k<=0){
            return false; 
        }
    }
    else{
        return false; 
    }
    return true;
}

void SettingCommand::execute() {
    // Notify the client it needs to get input from the user, as well as greet the user
    dio->write(string("The current KNN parameters are:")
                + string(" K = ") + to_string(data->getk())
                + ", distance metric = " + data->getDisName() + "\n");

    string input = dio->read();

    // go next if user press enter
    if (input.empty()) {
        return;
    }
    
    vector<string> vec;
    getInput(vec, input);

    // If too little arguments were given
    if (vec.size() < 2) {
        dio->write("too few arguments\n");
        return;
    }

    // Validating the K value
    bool validK=isValidK(vec[0]);
    int k;
    if (validK)
        {
            k = stoi(vec[0]);
        }
        else
        {
            dio->write("Invalid value for K\n");
            return;
        }
    data->setK(k);
   

    string disName = vec[1];
    int disNum = 0;
    if (disName != "AUC" && disName != "MAN" && disName != "CHB" && disName != "CAN" && disName != "MIN")
    {
        dio->write("Invalid metric\n");
        return;
    }

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
    data->setDisName(disName);
    data->setDisType(disNum);
    
}