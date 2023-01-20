#include "SocketIO.h"

SocketIO::SocketIO(ServerSocket& socket) : socket(socket) {}

std::string SocketIO::read() {
    cout<<"read now"<<endl;//000000000000000000000000
    return socket.RecFromClient(10);
}

void SocketIO::write(const string &str) {
    socket.sendToClient(str);
}

// void SocketIO::stopRun() {
//     socket.stopRun();
// }