#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include "DisplayCommand.h"
#include "VectorHasher.h"


using namespace std;

DisplayCommand::DisplayCommand(DefaultIO *my_dio, Data *my_data) : Command(my_dio, my_data)
{
    this->description = "4. display results";
}

void DisplayCommand::execute()
{
    unordered_multimap<vector<double>, string, VectorHasher> vecShow = data->getTest()->getVecUnclassified();
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
    sResult += "Done.\n";
    dio->write(sResult);
}