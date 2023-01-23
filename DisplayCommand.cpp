#include <fstream>
#include <string>
#include <sstream>
#include "DisplayCommand.h"


using namespace std;

DisplayCommand::DisplayCommand(DefaultIO *my_dio, Data *my_data) : Command(my_dio, my_data)
{
    this->description = "4. display results";
}

void DisplayCommand::execute()
{

    if (!data->getTestIsInit() || !data->getTrainIsInit())
    {
        dio->write("please upload data\n");
        return;
    }
    if (!data->getIsClassified())
    {
        dio->write("please classify the data\n");
        return;
    }

    string sResult=data->getResult();
    dio->write(sResult);
}