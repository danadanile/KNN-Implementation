#include "UploadCommand.h"
#include "VectorUnclassified.h"
#include <sstream>

UploadCommand::UploadCommand(DefaultIO *my_dio, Data *my_data) : Command(my_dio, my_data)
{
    this->description = "1. upload an unclassified csv data file";
}
stringstream readFileContent(DefaultIO *dio)

//    string buffer;
//    stringstream ss;
//    buffer.clear();
//    buffer = _defaultIO->read();
//    if (buffer == "file end") {
//        return ss;
//    }
//    buffer.erase(buffer.find_last_not_of('\r') + 1);
//    ss << buffer;
//    while (true) {
//        cout<<"enter while"<<endl;
//        buffer.clear();
//        buffer = _defaultIO->read();
//        cout<<buffer<<endl;
//        if (buffer == "file end") {
//            break;
//        }
//        buffer.erase(buffer.find_last_not_of('\r') + 1);
//        ss << '\n'
//           << buffer;
//    }
//    cout<<"func end"<<endl;
//    return ss;

{
    string buffer;
    stringstream stream;
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
    string buffer;
    dio->write("Please upload your local train CSV file.\n");
    // string fname = dio->read();
    if (dio->read() == "invalid input")
    {
        cout<<"fail"<<endl;
        return;
        cout<<"i dont succed"<<endl;
    }
    stringstream stream = readFileContent(dio);
    cout<<"read done"<<endl;
    buffer.clear();
    data->SetIsClassified(false);

    try
    {
        if (data->getTrainIsInit())
        {
            delete data->getTrain();
        }
        data->setTrain(stream);
        dio->write("Upload complete.\n");
    }
    catch (const invalid_argument &er)
    {
        if (data->getTestIsInit())
        {
            delete data->getTest();
            data->setTestIsInit(false);
        }
        dio->write("invalid input.\n");
        data->setTrainIsInit(false);
        return;
    }

    dio->write("Please upload your local test CSV file.\n");
    if (dio->read() == "invalid input")
    {
        return;
    }
    stringstream streamTest=readFileContent(dio);

    try
    {
        if (data->getTestIsInit())
        {
            delete data->getTest();
        }
        data->setTest(streamTest);
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

/// /home/danadanilenko/CLionProjects/testEx4/iris_Unclassified.csv
/// /home/danadanilenko/CLionProjects/testEx4/iris_classified.csv
// string getDescription(){
//     return "1. upload an unclassified csv data file";
// }
