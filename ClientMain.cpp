#include <iostream>
#include "ClientSocket.h"
#include "Client.h"
#define MAX_TO_GET 4096
#define FINISH_CONNECTION "finish connection"
using namespace std;



int main(int argc, char **argv)
{
    if (argc != 3){
        cout << "invalid argument" << endl;
        return 0;
    }

    // check the port.
    
    int port = -1;
    string strPort = string(argv[2]);
    if (ClientSocket::isPort(strPort)){
        port = stoi(argv[2]);
    }
    if (port == -1){
        cout << "the port is not valid." << endl;
        return 0;
    }

        ClientSocket* clientS = new ClientSocket(port, argv[1]);
        Client* cli = new Client(clientS);
    try{
        cli->start();
        clientS->closeClient();
        return 0;
    }
    catch (const runtime_error &er)
    { // to exit the client
        cout << er.what() << endl;
        clientS->closeClient();
        return 0;
    }
}
