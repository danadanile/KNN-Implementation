#ifndef CLIENTSOCKET_H_
#define CLIENTSOCKET_H_
#include <string>
using namespace std;

class ClientSocket {
    /// @brief client class deal with socket communication
    int sock;

public:
    /// @brief constructor
    /// @param portC the port
    /// @param ip the ip
    ClientSocket(const int portC, const char* ip);

    /// @brief checks if port is valid
    /// @param strPort
    /// @return true if valid
    static bool isPort(string &strPort);

    /// @brief recive message from server
    /// @param sizeToGet the size of the message to read
    /// @return the message
    const string recFromServer(int sizeToGet);

    /// @brief recive message from server
    /// @param sizeToGet the size of the message to read
    /// @return the message
    const string recFromServerSize(int sizeToGet);

    /// @brief send message to server
    /// @param str the message to send
    void sendToServer(string &str);

    /// @brief close client conection
    void closeClient();

};
#endif