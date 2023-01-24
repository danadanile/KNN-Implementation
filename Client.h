#ifndef CLIENT_H_
#define CLIENT_H_
#include <fstream>
#include <string>
#include <iostream>
#include "DefaultIO.h"
#include "StandartIO.h"
#include "SocketIO.h"
#include "ClientSocket.h"
using namespace std;


/// @brief client class
class Client {
private:
   
    char* ip_address;
    int port_num;
    string message;
    StandartIO* userDio;
    SocketIO* clientDio;
    ClientSocket* clientSock;

    /// @brief user input.
    /// @return the input.
    static string userInput();

    /// @brief upload func task.
    void upload();

    /// @brief the settings task.
    void settings();

    /// @brief class classifyData
    void classifyData();

    /// @brief class display task. 
    void display();

    /// @brief class download task.
    void download();

    /// @brief print msg
    /// @param s string to print.
    void printMsg(string s);

    /// @brief get from user.
    /// @param s to get.
    void getFromUser(string& s);

    /// @brief add zero to string
    /// @param input woth zeros.
    void addZeros(string &input);

    /// @brief write to file.
    /// @param resultPath of string.
    /// @param output what to file.
    void writeToFile(const string& resultPath, const string& output);



public:

    /// @brief constructor client.
    /// @param clientS the client sock.
    Client(ClientSocket* clientS);

    /// @brief fun start the cli.
    void start();

    //communicate function.
    void communicate();
};

#endif 