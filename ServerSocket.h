#ifndef SERVERSOCKET_H_
#define SERVERSOCKET_H_

#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class ServerSocket
{
    /// @brief server class
    int server_port;
    int sock;
    string msg;

public:
    /// @brief
    /// @param disType
    ServerSocket(int disType);

    /// @brief check validation of port
    /// @param strPort port number
    /// @return true if valid
    static bool IsPort(string &strPort);

    /// @brief conecting to client
    /// @return return the client socket
    int enterClient();

    void closeServer();
};
#endif