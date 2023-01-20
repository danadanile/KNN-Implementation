#include <netinet/in.h>
#include <unistd.h>
#include "ServerSocket.h"
#include "CheckFuncs.h"


ServerSocket::ServerSocket(int port) : sock(socket(AF_INET, SOCK_STREAM, 0))
{
    server_port = port;
    msg = ""; // ret messege.
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0)
    {
        perror("error listening to a socket");
    }
}

void ServerSocket::enterClient()
{
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len); // two socket
    if (client_sock < 0)
    {
        perror("error accepting client");
    }
}

bool ServerSocket::IsPort(string &strPort)
{
    int port = 0;
    if (CheckFuncs::isNumeric(strPort))
    {
        port = stoi(strPort);
        if (port < 1024 || port > 65535)
        { 
            cout<< "invalid argument"<<endl;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else{
        cout<< "invalid argument"<<endl;
        return 0;
    }
}

const string ServerSocket::RecFromClient(int sizeToGet)
{
    char bufferSize[sizeToGet + 1] = {0}; // for the message
    int read_bytes = recv(client_sock, bufferSize, sizeToGet, 0);

    if (read_bytes == 0)
    {
        throw runtime_error("connection closed");
        // connection is closed
    }
    else if (read_bytes < sizeToGet)
    {
        throw runtime_error("not all data sent");
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
    else
    {
        throw invalid_argument("error");
    }
    

    char buffer[sizeInput + 1] = {0};

    read_bytes = recv(client_sock, buffer, sizeInput, 0);
    if (read_bytes == 0)
    {
        throw runtime_error("connection closed");
        // connection is closed
    }
    else if (read_bytes < 0)
    {
        throw invalid_argument("erorr");
    }
    else if (read_bytes < sizeInput)
    {
        throw runtime_error("not all data sent");
        // error
    }
    string strRet(buffer);
    return strRet;
}

void ServerSocket::sendToClient(const string &str)
{
    int sent_bytes = send(client_sock, str.c_str(), str.length(), 0);
    if (sent_bytes < 0)
    {
        perror("error sending to client");
    }
}

void ServerSocket::closeClient()
{
    close(client_sock);
}

void ServerSocket::closeServer()
{
    close(sock);
}
