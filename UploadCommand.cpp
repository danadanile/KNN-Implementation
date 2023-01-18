#include "UploadCommand.h"
#include "VectorUnclassified.h"

UploadCommand::UploadCommand(DefaultIO *my_dio, Data *my_data) : Command(my_dio, my_data)
{
    this->description = "1. upload an unclassified csv data file";
}

void UploadCommand::execute()
{

    dio->write("Please upload your local train CSV file.\n");
    string fname = dio->read();
    data->SetIsClassified(false);

    try
    {
        if(data->getTrainIsInit()){
            delete data->getTrain();
        }
        data->setTrain(fname);

    }
    catch (const invalid_argument &er)
    {
        if(data->getTestIsInit()){
            delete data->getTest();
            data->setTestIsInit(false);
        }
        dio->write("invalid input.\n");
        data->setTrainIsInit(false);
        return;
    }

    
    dio->write("Please upload your local test CSV file.\n");
    string fnameTest = dio->read();
    try
    {
        if(data->getTestIsInit()){
            delete data->getTest();
        }
        data->setTest(fnameTest);
    }
    catch (const invalid_argument &er)
    {
        dio->write("invalid input.\n");
        data->setTestIsInit(false);
        delete data->getTrain();
        data->setTrainIsInit(false);
        return;
    }

    data->setTrainIsInit(true);
    data->setTestIsInit(true);
    dio->write("Upload complete.\n");
    }


///home/danadanilenko/CLionProjects/testEx4/iris_Unclassified.csv
///home/danadanilenko/CLionProjects/testEx4/iris_classified.csv
// string getDescription(){
//     return "1. upload an unclassified csv data file";
// }
