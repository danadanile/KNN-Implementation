#include "Client.h"
#include <iostream>

Client::Client(SocketIO *sockIO) : clientDio(sockIO)
{
    userDio = new StandartIO();
}

// std::string getInput() {
//     string buff;
//     getline(cin,buff);
//     return buff;
// }

void printTo(string s)
{
    cout << s << endl;
}

// bool validInt(string& str,int& choose) {
//     stringstream intStream;
//     intStream << str;
//     if (!(intStream >> choose) || !intStream.eof()) {
//         return false;
//     }
//     return true;
// }

/// @brief checks if file can be open
/// @param path file path
/// @param openFile ifstream
/// @return true is can open.
bool openFile(string &path, ifstream &openFile)
{
    openFile.open(path);
    retur openFile.is_open();
}

bool Client::upload()
{
    string mess, path;
    mess = clientDio->read();
    // client->socketRead(message,client->getSocket());
    printTo(mess);
    getline(cin, path);
    ifstream openFile;
    if (!openFile(path, openFile))
    {
        mess = "invalid input";
    }
    else
    {
        mess = "suceed";
    }
    clientDio->write(mess);
    // client->socketWrite(message,client->getSocket());
    if (mess == "invalid input")
    {
        // cout << message << endl;
        userDio->write(mess);
        return false;
    }
    string buffer;
    while (openFile)
    {
        buffer.clear();
        getline(openFile, buffer);
        clientDio->write(buffer);
        // client->socketWrite(buffer,client->getSocket());
    }
    buffer = "end of file";
    clientDio->write(buffer);
    // client->socketWrite(buffer,client->getSocket());
    buffer.clear();
    buffer = clientDio->read();
    // client->socketRead(buffer,client->getSocket());
    cout << buffer << endl;
    if (buffer == "invalid input")
    {
        return false;
    }
    return true;
}