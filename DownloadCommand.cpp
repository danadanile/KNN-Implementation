#include <string>
#include <sstream>
#include "DownloadCommand.h"

using namespace std;

DownloadCommand::DownloadCommand(DefaultIO *my_dio, Data *my_data) : Command(my_dio, my_data)
{
    this->description = "5. download results";
}

void DownloadCommand::execute()
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