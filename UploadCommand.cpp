#include "UploadCommand.h"

UploadCommand::UploadCommand(DefaultIO *dio)
{
    this->description = "1. upload an unclassified csv data file";
    this->m_dio=dio;
}
void Command::execute(Data &data){
    string fname = m_dio->read();
    //data.setVectorMap();



}
