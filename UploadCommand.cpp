#include "UploadCommand.h"
#include <sstream>

UploadCommand::UploadCommand(DefaultIO *my_dio, Data *my_data) : Command(my_dio, my_data)
{
    this->description = "1. upload an unclassified csv data file";
}
stringstream readFileContent(DefaultIO *dio)
{
   
    stringstream stream;
    string buffer;
    buffer.clear();
    buffer = dio->read();
    if (buffer != "file end")
    {
        buffer.erase(buffer.find_last_not_of('\r') + 1);
        stream << buffer;
        while (true)
        {
            buffer.clear();
            buffer = dio->read();
            if (buffer == "file end")
            {
                break;
            }
            buffer.erase(buffer.find_last_not_of('\r') + 1);
            stream << '\n'
                   << buffer;
        }
    }
    return stream;
}


void UploadCommand::execute()
{
    //SENT-PLEASE UPLOAD..
    string buffer;
    dio->write("Please upload your local train CSV file.");

    //GET-"READ DONE" IN CLIENT: ELSE:
    if (dio->read() == "invalid input"){

        //DELETE EXITS FILES:
        if (data->getTrainIsInit()){
            delete data->getTrain();
            data->setTrainIsInit(false);
        }      
        if (data->getTestIsInit()){
            delete data->getTest();
            data->setTestIsInit(false);
        }
        return;
    }

    //GET-READ DONE IN CLIENT-READ ALL HERE:
    stringstream stream = readFileContent(dio);
    buffer.clear();
    data->setIsClassified(false);
    try
    {
        //IF ALLRDY EXIST-DELETE:
        if (data->getTrainIsInit()){
            delete data->getTrain();
        }
        //ENTER TO VECTOR MAP:
        data->setTrain(stream);
        dio->write("Upload complete.\n");
    }
    catch (const invalid_argument &er)
    { 
        //SOMTHING GOT WRONG..Init TestMap:
        if (data->getTestIsInit()){
            delete data->getTest();
            data->setTestIsInit(false);
        }
        dio->write("invalid input");
        data->setTrainIsInit(false);
        return;
    }


    //ROUND 2:

    //SENT-PLEASE UPLOAD..
    dio->write("Please upload your local test CSV file.");

    //GET-"READ DONE" IN CLIENT: ELSE:
    if (dio->read() == "invalid input"){

        //DELETE EXITS FILES:
        if (data->getTrainIsInit()){
            delete data->getTrain();
            data->setTrainIsInit(false);
        }      
        if (data->getTestIsInit()){
            delete data->getTest();
            data->setTestIsInit(false);
        }
        return;
    }

    //GET-READ DONE IN CLIENT-READ ALL HERE:
    stringstream streamTest=readFileContent(dio);

    try
    {
        //IF ALLRDY EXIST-DELETE:
        if (data->getTestIsInit()) {
            delete data->getTest();
        }

        //ENTER TO VECTOR MAP:
        data->setTest(streamTest);


        //CHECK SIZE TWO VECTOR MAPS:
        if(data->getTest()->getOneVecLength() !=data->getTrain()->GetVectorLength()){
            throw invalid_argument("invalid input");
        }
    }

    catch (const invalid_argument &er)
    {
        dio->write("invalid input");
        data->setTestIsInit(false);
        delete data->getTrain();
        data->setTrainIsInit(false);
        return;
    }

    data->setTrainIsInit(true);
    data->setTestIsInit(true);
    dio->write("Upload complete.");
}


