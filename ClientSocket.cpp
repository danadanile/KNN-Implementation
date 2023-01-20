#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "ClientSocket.h"
#include "CheckFuncs.h"

/// @brief constructor
/// @param portC the port
/// @param ip the ip
ClientSocket::ClientSocket(const int portC, const char *ip)
{

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        throw runtime_error("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip);
    sin.sin_port = htons(portC);
    if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        throw runtime_error("error connecting to server");
    }
}

/// @brief checks if port is valid
/// @param strPort 
/// @return true if valid
bool ClientSocket::isPort(string &strPort)
{
    int port = 0;
    if (CheckFuncs::isNumeric(strPort))
    {
        port = stoi(strPort);
        if (port < 1025 || port > 65535)
        {
            cout << "invalid argument" << endl;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        cout << "invalid argument" << endl;
        return 0;
    }
}

/// @brief recive message from server
/// @param sizeToGet the size of the message to read
/// @return the message
const string ClientSocket::recFromServer(int sizeToGet)
{
    string strRet = "";
    char buffer[sizeToGet] = {0};
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0)
    {
        // connection is closed
        throw runtime_error("connection is closed");
    }
    else if (read_bytes < 0)
    {
        throw runtime_error("error");
        // error
    }
    else
    {
        strRet = string(buffer);
    }

    return strRet;
}

/// @brief send message to server
/// @param str the message to send
void ClientSocket::sendToServer(string &str)
{
    int data_len = str.length();

    int sent_bytes = send(sock, str.c_str(), data_len, 0);
    if (sent_bytes < 0)
    {
        throw runtime_error("connection is closed");
        //error
    }
}

/// @brief close client conection 
void ClientSocket::closeClient()
{
    close(sock);
}
