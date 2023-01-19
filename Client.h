#ifndef CLIENT_H_
#define CLIENT_H_

#include <fstream>
#include <string>
#include <iostream>
#include "DefaultIO.h"
#include "StandartIO.h"
#include "SocketIO.h"
#include "ClientSocket.h"
using namespace std;

class Client {
private:
   
    char* ip_address;
    int port_num;
    string message;
    StandartIO* userDio;
    SocketIO* clientDio;
    ClientSocket* clientSock;

    static string userInput();
    void upload();
    void settings();
    void classify();
    void display();
    void download();
    string printMess(string s);
    string getFromUser(string s);

    //void general();
    //void downloadIntoFile(const string& path, const string& output);

public:
    Client(ClientSocket* clientS);
    void start();
    void communicate();
};

#endif 