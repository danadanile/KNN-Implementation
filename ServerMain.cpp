#include <sstream>
#include "DistanceType.h"
#include "VectorMap.h"
#include "CheckFuncs.h"
#include "ServerSocket.h"
#include "ServerSocket.h"
#include "SocketIO.h"
#include "DefaultIO.h"
#include "Cli.h"
#include <cstdlib>
#define P 2
#define CHAR_SUM_INT 10

using namespace std;



int main(int argc, char **argv)
{

    // check num of arg.
    if (argc != 2){
        cout << "invalid argument" << endl;
        return 0;
    }
   

    // check the port.
    int port = -1;
    string strPort = string(argv[1]);
 
    if (ServerSocket::IsPort(strPort)){
        port = stoi(argv[1]);
    }
    else{    
        return 0;
    }
    if (port == -1){
        cout << "invalid argument" << endl;
        return 0;
    }

    // create server .
    ServerSocket serS(port);
    SocketIO* sockIO = new SocketIO(serS);
    serS.enterClient();
    Cli* cli = new Cli(sockIO);
    cli->start();

    // close
    serS.closeServer();
    return 0;
}
