#include "UploadCommand.h"
#include "VectorUnclassified.h"

UploadCommand::UploadCommand(DefaultIO *dio)
{
    this->description = "1. upload an unclassified csv data file";
    this->m_dio=dio;
}
void Command::execute(Data &data){
    m_dio->write("Please upload your local train CSV file.\n");
    string fname = m_dio->read();
    //data.setVectorMap();

    VectorMap mapObj(fname);
    if (mapObj.getSizeMap() != 0)
    {
        m_dio->write("Upload complete.\n");
        m_dio->write("Please upload your local test CSV file.\n");
        fname = m_dio->read();
        VectorUnclassified mapUnClass(fname);
            if (mapObj.getSizeMap() != 0){
                m_dio->write("Upload complete.\n");
            }
            else{
                throw invalid_argument("invalid input"); ////    
            } 
    }
    else{
        throw invalid_argument("invalid input"); //// 
    }
}


