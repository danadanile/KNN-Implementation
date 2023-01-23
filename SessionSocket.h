#ifndef SESSIONSOCKET_H_
#define SESSIONSOCKET_H_
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

/// @brief responsability for connection with one client.
class SessionSocket {
    /// @brief session class
    int client_sock;

public: 

    /// @brief constructor of ssesion sock.
    /// @param client_sock for connecto to one client.
    SessionSocket(int client_sock);

    /// @brief receve from client.
    /// @param sizeToGet 
    /// @return str of get from server.
    const string RecFromClient(int sizeToGet);

    /// @brief sent to client msg.
    /// @param str to send by size.
    void sendToClientSize(const string &str);

    /// @brief sent to client msg.
    /// @param str to send.
    void sendToClient(const string &str);

    //close connection with client.
    void closeClient();
};
#endif