#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "ClientSocket.h"
#include "CheckFuncs.h"


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


const string ClientSocket::recFromServerSize(int sizeToGet)
{
    char bufferSize[sizeToGet+1] = {0}; // for the message
    int expected_data_len = sizeof(bufferSize);
    int read_bytes = recv(sock, bufferSize, sizeToGet, 0);
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

    bool flag = false;
    int sizeInput = 0;
    string strSize = string(bufferSize, sizeToGet);

    if (CheckFuncs::isNumeric(strSize))
    {
        sizeInput = stoi(strSize);
        if (sizeInput < 0)
        {
            throw invalid_argument("error");
        }
    }
    else{
        throw invalid_argument("error");
    }
    char buffer[sizeInput + 1] = {0};
    read_bytes = recv(sock, buffer, sizeInput, 0);
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
    else if (read_bytes < sizeInput)
    {
        throw runtime_error("not all data sent");
        // error
    }
    string strRet(buffer);
    return strRet;
}

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

void ClientSocket::closeClient()
{
    close(sock);
}
