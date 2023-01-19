#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include <cstring>
#include <iostream>
#include "ServerSocket.h"
#include "DefaultIO.h"
using namespace std;

class SocketIO : public DefaultIO {
private:
    ServerSocket& socket;

public:
    /// @brief constructor
    /// @param socket  the server socket
    SocketIO(ServerSocket& socket);

    /// @brief read user input and return strung
    /// @return string input
    string read() override;

    /// @brief write output
    /// @param str the output
    void write(const string &str) override;

    /// @brief finish run
    void stopRun();
};

#endif