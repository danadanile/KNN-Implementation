#ifndef CLIENT_H_
#define CLIENT_H_

#include <fstream>
#include <string>
#include <iostream>
#include "DefaultIO.h"
#include "StandartIO.h"
#include "SocketIO.h"
using namespace std;

class Client {
private:
   
    char* ip_address;
    int port_num;
    string message;
    StandartIO* userDio;
    SocketIO* clientDio;
    //std::unique_ptr<ClientSocket> m_socket;

    static string userInput();
    void upload();
    //void download();
    //void general();
    //void downloadIntoFile(const string& path, const string& output);

public:
    Client(SocketIO *);
    void communicate();
};


#endif 