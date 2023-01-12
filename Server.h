#ifndef SERVER_H_
#define SERVER_H_
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class Server {
    /// @brief server class
    int server_port;
    int sock;
    string msg;
    int client_sock;

public: 
    Server(int disType);
    static bool IsPort(string &strPort);
    void enterClient();
    const string RecFromClient(int sizeToGet);
    void sendToClient(string &str);
    void closeClient();
    void closeServer();
};
#endif