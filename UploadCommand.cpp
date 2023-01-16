#include "UploadCommand.h"
#include "VectorUnclassified.h"

UploadCommand::UploadCommand(DefaultIO *dio, Data *data):Command(dio,data)
{
    this->description = "upload an unclassified csv data file";
    // this->dio=dio;
    // this->data=data;
}

void Command::execute(){
    dio->write("Please upload your local train CSV file.\n");
    string fname = dio->read();
    //data.setVectorMap();

    VectorMap mapObj(fname);
    if (mapObj.getSizeMap() != 0)
    {
        dio->write("Upload complete.\n");
        dio->write("Please upload your local test CSV file.\n");
        fname = dio->read();
        VectorUnclassified mapUnClass(fname);
            if (mapObj.getSizeMap() != 0){
                dio->write("Upload complete.\n");
            }
            else{
                throw invalid_argument("invalid input"); ////    
            } 
    }
    else{
        throw invalid_argument("invalid input"); //// 
    }
}

// string getDescription(){
//     return "1. upload an unclassified csv data file";
// }
