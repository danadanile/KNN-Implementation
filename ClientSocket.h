#ifndef CLIENTSOCKET_H_
#define CLIENTSOCKET_H_
#include <string>
using namespace std;

class ClientSocket {
    /// @brief client class
    int sock;

public: 
    ClientSocket(const int portC, const char* ip);
    static bool isPort(string &strPort);
    const string recFromServer(int sizeToGet);
    const string recFromServerSize(int sizeToGet);
    void sendToServer(string &str);
    void closeClient();

};
#endif