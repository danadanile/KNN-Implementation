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
    // data.setVectorMap();

    bool erorWhithFile = false;
    try
    {
        //data->test
        data->setTrain(fname);
        data->setTrainIsInit();
    }
    catch (const invalid_argument &er)
    {
        erorWhithFile = true;
    }

    if (erorWhithFile)
    {
        dio->write("invalid input.\n");
        return;
    }
    else
    {
        dio->write("Please upload your local test CSV file.\n");
        string fnameTest = dio->read();
        try
        {
            data->setTest(fnameTest);
        }
        catch (const invalid_argument &er)
        {
            erorWhithFile = true;
        }

        if (erorWhithFile)
        {
            dio->write("invalid input.\n");
            return;
        }
        else
        {
            dio->write("Upload complete.\n");
        }
    }
}

// string getDescription(){
//     return "1. upload an unclassified csv data file";
// }
