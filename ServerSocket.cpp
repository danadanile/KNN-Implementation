#include <netinet/in.h>
#include <unistd.h>
#include "ServerSocket.h"
#include "CheckFuncs.h"
using namespace std;

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

int ServerSocket::enterClient()
{
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len); // two socket
    if (client_sock < 0)
    {
        perror("error accepting client");
    }
    return client_sock;
}

bool ServerSocket::IsPort(string &strPort)
{
    int port = 0;
    if (CheckFuncs::isNumeric(strPort))
    {
        port = stoi(strPort);
        if (port < 1024 || port > 65535)
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

void ServerSocket::closeServer()
{
    close(sock);
}
