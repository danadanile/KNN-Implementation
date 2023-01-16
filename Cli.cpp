#include "Cli.h"
#include "UploadCommand.h"
#include "CheckFuncs.h"
#include "Data.h"
using namespace std;


Cli::Cli(DefaultIO* d_io) : d_io(d_io){
data = new Data();
//initialize commands array:
commands[0] = new UploadCommand(d_io, data);
commands[1] = new UploadCommand(d_io, data);
commands[2] = new UploadCommand(d_io,data);
commands[3] = new UploadCommand(d_io, data);
commands[4] = new UploadCommand(d_io, data);
//commands[1]=new SettingsCommand(d_io);
//commands[2]=new ClassifyCommand(d_io);
//commands[3]=new DisplayCommand(d_io);
//commands[4]=new DownloadCommand(d_io);


}

void Cli::start() {
    bool play = true;
    while(play){
        try{
            printMenu();
            play = chooseFromMenu();
        }
        catch(const invalid_argument &er){
            string error = er.what();
            d_io->write(error);
            continue;
        }
    }
}

void Cli::printMenu() {

    string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    int size = sizeof(commands)/sizeof(commands[0]);

    for(int i=0; i<size-1; i++){
        menu += to_string(i+1) + ". ";
        menu +=commands[i]->getDescription();
        menu += "\n";
    }
        menu +=commands[size-1]->getDescription();
    d_io->write(menu);

}

bool Cli::chooseFromMenu() {

    string strChoose=d_io->read();
    if(!checkChooseValid(strChoose)){
    throw invalid_argument("the choose is not valid.");//??????????????
    }
    int choose=stoi(strChoose);
    if(choose==8){
        return false; //finish
    }
    commands[choose-1]->execute();
    return true; //comtinue the loop
}


bool Cli::checkChooseValid(string choose){
    if(CheckFuncs::isNumeric(choose)) {
        int k = stoi(choose);
        int size = sizeof(commands)/sizeof(commands[0]);
        if(k<0 ||((k>=size)&&(k!=8))){
            return false; 
        }
    }
    else{
        return false; 
    }
    return true;
}

