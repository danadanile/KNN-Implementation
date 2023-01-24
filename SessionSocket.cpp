#include <netinet/in.h>
#include <unistd.h>
#include "SessionSocket.h"
#include "CheckFuncs.h"
using namespace std;


SessionSocket::SessionSocket(int client_sock) : client_sock(client_sock)
{
}


const string SessionSocket::RecFromClient(int sizeToGet)
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

void SessionSocket::sendToClient(const string &str)
{
    int sent_bytes = send(client_sock, str.c_str(), str.length(), 0);
    if (sent_bytes < 0)
    {
        perror("error sending to client");
    }
}

void SessionSocket::sendToClientSize(const string &str)
{
    //ADD ZEROS:
    string strSent=str;
    int inputLength = strSent.length();
    // declare a stream object
    string str1 = to_string(inputLength);
    strSent.insert(0, str1); // Inserts str2 in str1 starting from 0 index of str1
    int addZero = 10 - CheckFuncs::count_digit(inputLength);
    strSent.insert(0, addZero, '0'); // insert 0 addZero times in position 0;

    //The Main Function Send:
    int sent_bytes = send(client_sock, strSent.c_str(), strSent.length(), 0);
    if (sent_bytes < 0)
    {
        perror("error sending to client");
    }
}

void SessionSocket::closeClient()
{
    close(client_sock);
}