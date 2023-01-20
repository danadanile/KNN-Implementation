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
#include "DistanceType.h"
#include "CheckFuncs.h"
#include <thread>
#define MAX_TO_GET 4096
#define SIZE_READ 10
using namespace std;


// Client::Client(ClientSocket *clientS){
//     // clientSock = new ClientSocket();
// }

Client::Client(ClientSocket* clientS) : clientSock(clientS){
}

void Client::printMess(string s){
    cout << s << endl;
}

void Client::getFromUser(string& s){
    getline(cin, s);
    return;
}


void Client::upload()
{
    for (int i = 0; i < 2; i++)
    {
        string message, path;

        // read description task:
        message = clientSock->recFromServer(MAX_TO_GET);
        printMess(message);

        //get path from user:
        getFromUser(path);
        cout<<path<<endl;
        ifstream openFile;
        openFile.open(path);
        printMess("open");

        if (!openFile.is_open()){
            message = "invalid input";
            printMess(message);
        }
        else
        {
            message = "Succeed";
            printMess(message);
        }
        // write
        clientSock->sendToServer(message);
        // client->socketWrite(message,client->getSocket());
        if (message == "invalid input")
        {
            // cout << message << endl;
            printMess(message);
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

        printMess(buffer); // print complete or not

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
    printMess(message);
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
        printMess(message);
        // printToScreen(message);
    }
}

void Client::display() {
    string message;
    message = clientSock->recFromServer(MAX_TO_GET);
    printMess(message);
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



void Client:: addZeros(string &input)
{
    int inputLength = input.length();
    // declare a stream object
    string str = to_string(inputLength);
    input.insert(0, str); // Inserts str2 in str1 starting from 0 index of str1
    int addZero = 10 - CheckFuncs::count_digit(inputLength);
    input.insert(0, addZero, '0'); // insert 0 addZero times in position 0;
}


bool checkChooseValid(string choose)
{
    if (CheckFuncs::isNumeric(choose))
    {
        int c = stoi(choose);
        cout << c << endl;
        if (c < 1 || c > 8 || c == 7)
        {
            return false;
        }
    }
    else
    {

        return false;
    }

    return true;
}


void Client::start(){

    try
    {
        while (true)
        {
            string msgFromServer, chooseInput;
            msgFromServer="";
            chooseInput="";

            //get the menu from server:
            msgFromServer = clientSock->recFromServer(MAX_TO_GET); 
            printMess(msgFromServer);

            //the choose of the user:
            getFromUser(chooseInput);

            //not valid choose
            if(!checkChooseValid(chooseInput)){
                //send to server return to menu
                string strMenu="retMenu";
                addZeros(strMenu);
                clientSock->sendToServer(strMenu);
                continue; //to the menu.
            }

            int choose = stoi(chooseInput);
            //send the choose to server:
            addZeros(chooseInput);
            clientSock->sendToServer(chooseInput);

            // //checks that everything is fine:
            // msgFromServer = clientSock->recFromServer(MAX_TO_GET);
            // if(msgFromServer!="all is well"){
            //     throw runtime_error("error");
            // }


            //react by the match function:
            switch (choose) {
                case 1:
                    upload();
                    break;
                case 2:
                    settings();
                    break;
                case 3:
                    //classify();
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
        return ;
    }


}






