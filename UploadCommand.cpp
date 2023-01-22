#include "UploadCommand.h"
#include "VectorUnclassified.h"
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
    if (dio->read() == "invalid input.\n"){

        //DELETE EXITS FILES:
        if (data->getTrainIsInit()){
            delete data->getTrain();
            data->setTrainIsInit(false);
        }      
        if (data->getTestIsInit()){
            delete data->getTest();
            data->setTestIsInit(false);
        }
        cout<<"fail"<<endl;
        return;
    }

    //GET-READ DONE IN CLIENT-READ ALL HERE:
    stringstream stream = readFileContent(dio);
    cout<<"here1"<<endl;
    buffer.clear();
    data->SetIsClassified(false);
    cout<<"here2"<<endl;
    try
    {
        //IF ALLRDY EXIST-DELETE:
        if (data->getTrainIsInit()){
            delete data->getTrain();
        }
    cout<<"here3"<<endl;
        //ENTER TO VECTOR MAP:
        data->setTrain(stream);
    cout<<"here4"<<endl;
        //CHECK K:
        if(data->getTrain()->getSizeMap()<data->getK()){
            cout<<"k prob"<<endl;
            //throw invalid_argument("invalid input.\n");
            data->setK(data->getTrain()->getSizeMap());
            
        }
        dio->write("Upload complete.\n");
    }
    catch (const invalid_argument &er)
    { 
        //SOMTHING GOT WRONG..Init TestMap:
        if (data->getTestIsInit()){
            delete data->getTest();
            data->setTestIsInit(false);
        }
        dio->write("invalid input.\n");
        data->setTrainIsInit(false);
        return;
    }


    //ROUND 2:

    //SENT-PLEASE UPLOAD..
    dio->write("Please upload your local test CSV file.");

    //GET-"READ DONE" IN CLIENT: ELSE:
    if (dio->read() == "invalid input.\n"){

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

        //CHECK K:
        if(data->getTest()->getSizeMap()<data->getK()){
            //throw invalid_argument("invalid input.\n");
            cout<<"k prob"<<endl;
            data->setK(data->getTest()->getSizeMap());
        }

        //CHECK SIZE TWO VECTOR MAPS:
        if(data->getTest()->GetVectorLength()!=data->getTrain()->GetVectorLength()){
            throw invalid_argument("invalid input.\n");
            cout<<"size prob"<<endl;
        }
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


