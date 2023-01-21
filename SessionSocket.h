#ifndef SESSIONSOCKET_H_
#define SESSIONSOCKET_H_
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class SessionSocket {
    /// @brief session class
    int client_sock;

public: 
    SessionSocket(int client_sock);
    const string RecFromClient(int sizeToGet);
    void sendToClientSize(const string &str);
    void sendToClient(const string &str);
    void closeClient();
};
#endif