#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include <cstring>
#include <iostream>
#include "SessionSocket.h"
#include "DefaultIO.h"
using namespace std;

/// @brief socket io responsability for socket and write and read.
class SocketIO : public DefaultIO {
private:
    SessionSocket& socket;

public:
    /// @brief constructor
    /// @param socket  the server socket
    SocketIO(SessionSocket& socket);

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