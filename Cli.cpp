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
                  new DownloadCommand(dio, data), new UploadCommand(dio, data)};
}

void Cli::start() {
    // Print the menu
    string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    int size = commands.size();
    for (int i = 0; i < size; ++i) {
        menu += commands[i]->getDescription() + "\n";
    }
    menu += "8. exit\n";
    


    bool flag = false;
    while(true) {
        //show the menu

        dio->write(menu);
        // Execute the chosen command
        int index = -1;

        try {
            cout<<"in try"<<endl;
            string chooseStr=dio->read();
            cout<<chooseStr<<endl;//00000000000000000000000
            cout<<chooseStr<<endl;//00000000000000000000000
            index = stoi(chooseStr);
            cout<<index<<endl;//00000000000000000000000
            //if a not number input
        } catch (const std::exception& e) {
            dio->write("invalid input\n");
            //flag = true;
            continue;
        }
        //flag = false;
        //exit option
        if (index == 8) {
            dio->write("exit\n");
            //break;
        }

        //invalid option
        if (index <= 0 || index > size) {
            dio->write("invalid input\n");
            flag = true;
            continue;
        }

        //run option
        cout<<"execute(:"<<endl;
        commands[index - 1]->execute();
    }

    // try {
    //     SocketIO* socketIo = (SocketIO*) m_dio;
    //     socketIo->stopRunning();
    // } catch (const std::exception& e) {}
}

Cli::~Cli() {
    delete data;
    delete dio;

    for (int i = 0; i < commands.size(); ++i) {
        delete commands[i];
    }
}
