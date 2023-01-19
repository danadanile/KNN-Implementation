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
    void classifyTheData();
    void display();
    void download();
    string printMes(string s);
    string getFromUser(string s);
    void writeToFile(const string& resultPath, const string& output);

    //void general();
    //void downloadIntoFile(const string& path, const string& output);

public:
    Client(ClientSocket* clientS);
    void start();
    void communicate();
};

#endif 