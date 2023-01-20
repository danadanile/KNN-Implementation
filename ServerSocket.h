#ifndef SERVERSOCKET_H_
#define SERVERSOCKET_H_
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class ServerSocket {
    /// @brief server class
    int server_port;
    int sock;
    string msg;
    int client_sock;

public: 
    ServerSocket(int disType);
    static bool IsPort(string &strPort);
    void enterClient();
    const string RecFromClient(int sizeToGet);
    void sendToClientSize(const string &str);
    void sendToClient(const string &str);
    void closeClient();
    void closeServer();
};
#endif