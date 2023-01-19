#include "Client.h"
#include "ClientSocket.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <thread>
#include "DistanceType.h"
#include "CheckFuncs.h"
#define MAX_TO_GET 4096
#define SIZE_READ 10
using namespace std;

Client::Client(ClientSocket *clientS)
{
    // clientSock = new ClientSocket();////checkkkk
}

string Client::printMes(string s)
{
    cout << s << endl;
}
string Client::getFromUser(string s) //////delete
{
    getline(cin, s);
}

void Client::upload()
{
    for (int i = 0; i < 2; i++)
    {
        string message, path;
        // read
        message = clientSock->recFromServer(SIZE_READ);
        // client->socketRead(message,client->getSocket());
        printMes(message);
        getFromUser(path);
        ifstream openFile;
        openFile.open(path);

        if (!openFile.is_open())
        {
            message = "invalid input";
        }
        else
        {
            message = "Succeed";
        }
        // write
        clientSock->sendToServer(message);
        // client->socketWrite(message,client->getSocket());
        if (message == "invalid input")
        {
            // cout << message << endl;
            printMes(message);
            // return false;
        }
        string buffer;
        while (openFile)
        {
            buffer.clear();
            getline(openFile, buffer);
            clientSock->sendToServer(buffer);
            // client->socketWrite(buffer,client->getSocket());
        }
        buffer = "end file";
        clientSock->sendToServer(buffer);
        // client->socketWrite(buffer,client->getSocket());

        buffer.clear();
        buffer = clientSock->recFromServer(SIZE_READ);

        printMes(buffer); // print complete or not

        if (buffer == "invalid input")
        {
            return;
        }
        continue;
    }
}

void Client::settings()
{
    string message;
    message = clientSock->recFromServer(MAX_TO_GET);
    printMes(message);
    // cout << message << endl;
    message.clear();
    message = clientSock->recFromServer(MAX_TO_GET);
    // getline(cin,message);
    if (message.empty())
    {
        message = "continue";
        clientSock->sendToServer(message);
        return;
    }

    clientSock->sendToServer(message);
    
    message.clear();
    message = clientSock->recFromServer(MAX_TO_GET);
    // client->socketRead(message,client->getSocket());
    if (message != "valid")
    {
        printMes(message);
        // printToScreen(message);
    }
}

void Client::display() {
    string message;
    message = clientSock->recFromServer(MAX_TO_GET);
    printMes(message);
//    client->socketRead(msg,client->getSocket());
//    printToScreen(msg);
}

void Client::download(){
    string message = clientSock->recFromServer(MAX_TO_GET);
    string path;
    getline(cin, path); 
    std::thread thread(&Client::writeToFile, this, path, message);
    thread.detach();
}


void Client::writeToFile(const string& path, const string& output) {
    std::ofstream oFile;
    oFile.open(path);
    if (oFile.is_open()) {
        oFile << output;
        oFile.close();
    } else {
        //  printToScreen("invalid input");
    }
}



bool checkChooseValid(string choose)
{
    if (CheckFuncs::isNumeric(choose))
    {
        int c = stoi(choose);
        if (c < 1 || c > 8 || c == 7)
        {
            throw invalid_argument("invalid input");
        }
    }
    else
    {
        return c;
    }
    return 0;
}

void addZeros(string &input)
{
    int inputLength = input.length();
    // declare a stream object
    string str = to_string(inputLength);
    input.insert(0, str); // Inserts str2 in str1 starting from 0 index of str1
    int addZero = 10 - CheckFuncs::count_digit(inputLength);
    input.insert(0, addZero, '0'); // insert 0 addZero times in position 0;
}

void Client::start()
{

    try
    {
        while (true)
        {
            string msgFromServer, chooseInput;
            msgFromServer = "";
            chooseInput = "";

            // get the menu from server:
            msgFromServer = clientSock->recFromServer(MAX_TO_GET);
            // if (msgFromServer == "invalid input") {
            //     throw runtime_error("error");
            // }

            // the choose of the user:
            getline(std::cin, chooseInput); ///////////////changeName
            if (!checkChooseValid(chooseInput))
            {
                cout << "invalid input" << endl; ///////////////changeName
                // send to server return to menu
                clientSock->sendToServer() continue; // to the menu.
            }
            int choose = stoi(chooseInput);

            // send the choose to server:
            addZeros(userInput);
            clientSock->sendToServer(chooseInput);
            // checks that everything is fine:
            msgFromServer = clientSock->recFromServer(MAX_TO_GET);
            if (msgFromServer != "all is well")
            {
                throw runtime_error("error");
            }

            // react by the match function:
            switch (choose)
            {
            case 1:
                upload();
                break;
            case 2:
                settings();
                break;
            case 3:
                classify();
                break;
            case 4:
                display();
                break;
            case 5:
                download();
                break;
            case 8:
                return;
                break;
            }
        }
    }

    catch (const invalid_argument &er)
    {
        // to exit the client
        cout << er.what() << endl;
        return;
    }
}
