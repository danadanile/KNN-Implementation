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

public: 
    ServerSocket(int disType);
    static bool IsPort(string &strPort);
    int enterClient();
    void closeServer();
};
#endif