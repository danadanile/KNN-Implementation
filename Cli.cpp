#include "Cli.h"
#include "UploadCommand.h"
#include "CheckFuncs.h"
#include "Data.h"
#include "SettingCommand.h"
#include "ClassifyCommand.h"
#include "DisplayCommand.h"
#include "DownloadCommand.h"
using namespace std;


Cli::Cli(DefaultIO* dio) : dio(dio) {
    data = new Data();

    commands = {new UploadCommand(dio, data), new SettingCommand(dio, data),
                new ClassifyCommand(dio, data), new DisplayCommand(dio, data),
                new DownloadCommand(dio, data)};
}

void Cli::start() {

    //CREATE THE MENU:
    string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    int size = commands.size();
    for (int i = 0; i < size; ++i) {
        menu += commands[i]->getDescription() + "\n";
    }
    menu += "8. exit";

    bool flag = false;
    while(true) {
        //SENT THE MENU:
        dio->write(menu);
        // Execute the chosen command
        int index = -1;
        string chooseStr = dio->read();

        if(chooseStr=="retMenu"){
            continue;
        }

        try {
            index = stoi(chooseStr);
            //if a not number input
        } catch (const std::exception& e) {
            dio->write("invalid input");
            continue;
        }

        if (index == 8) {
            return;
        }

        //invalid option
        if (index <= 0 || index > size) {
            dio->write("invalid input");
            continue;
        }
        dio->write("valid");
        //run option
        commands[index - 1]->execute();
    }
}

Cli::~Cli() {
    delete data;
    delete dio;
    for (int i = 0; i < commands.size(); ++i) {
        delete commands[i];
    }
}