#include "SocketIO.h"
#define SIZE_READ 10

SocketIO::SocketIO(SessionSocket& socket) : socket(socket) {}

std::string SocketIO::read() {
    cout<<"read now"<<endl;//000000000000000000000000
    return socket.RecFromClient(SIZE_READ);
}

void SocketIO::write(const string &str) {
    socket.sendToClientSize(str);
}

