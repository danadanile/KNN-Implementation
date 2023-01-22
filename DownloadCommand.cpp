#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
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

    multimap<vector<double>, string> vecShow = data->getTest()->getVecUnclassified();

    string sResult = "";
    int count = 1;
    for (auto it = vecShow.begin(); it != vecShow.end(); ++it)
    {
        sResult += to_string(count);
        sResult += "\t";
        sResult += it->second;
        sResult += "\n";
        count++;
    }
    dio->write(sResult);

    // string data = "col1,col2,col3\nval1,val2,val3\nval4,val5,val6\n";
    // std::string filePath = "path/to/file.csv";
    // string filePath = dio->read();
    // //filePath += "/file.csv";
    // ofstream file(filePath);
    // if (file.is_open())
    // {
    //     file << sResult;
    //     file.close();
    // }
    // else
    // {
    //     // Handle the case where the file could not be opened
    // }
}