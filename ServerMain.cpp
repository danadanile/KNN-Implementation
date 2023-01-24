#include <sstream>
#include "ServerSocket.h"
#include "SessionSocket.h"
#include "SocketIO.h"
#include "DefaultIO.h"
#include "Cli.h"
#include <thread>
#define P 2

using namespace std;

void handleClient(int clientSock)
{
    //cout << "in thread handleClient " << clientSock << endl;
    SessionSocket sesS(clientSock);
    SocketIO *sockIO = new SocketIO(sesS);
    try 
    {
        Cli *cli = new Cli(sockIO);
        cli->start();
        delete cli;
    }
    catch (const runtime_error &er)
    {
    }

    sesS.closeClient();
}

int main(int argc, char **argv)
{

    // check num of arg.
    if (argc != 2)
    {
        cout << "invalid argument" << endl;
        return 0;
    }

    // check the port.
    int port = -1;
    string strPort = string(argv[1]);

    if (ServerSocket::IsPort(strPort))
    {
        port = stoi(argv[1]);
    }
    else
    {
        return 0;
    }
    if (port == -1)
    {
        cout << "invalid argument" << endl;
        return 0;
    }

    // create server .
    ServerSocket serS(port);
    while (true)
    {
        int clientSock = serS.enterClient();

        thread clientThread(&handleClient, clientSock);
        clientThread.detach();
    }

    // close
    serS.closeServer();
    return 0;
}
