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
#define MAX_TO_GET 4096
using namespace std;


bool checkChooseValid(string choose){
    if(CheckFuncs::isNumeric(choose)) {
        int c = stoi(choose);
        if(c<1 || c>8 || c==7){
            throw invalid_argument("invalid input");
        }
    }
    else{
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

Client::Client(ClientSocket* clientS) : clientSock(){
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
            // if (msgFromServer == "invalid input") {
            //     throw runtime_error("error");
            // }

            //the choose of the user:
            getline(std::cin, chooseInput); ///////////////changeName
            if(!checkChooseValid(chooseInput)){
                cout << "invalid input" << endl; ///////////////changeName
                //send to server return to menu
                clientSock->sendToServer()
                continue; //to the menu.
            }
            int choose = stoi(chooseInput);

            //send the choose to server:
            addZeros(userInput);
            clientSock->sendToServer(chooseInput);
            //checks that everything is fine:
            msgFromServer = clientSock->recFromServer(MAX_TO_GET);
            if(msgFromServer!="all is well"){
                throw runtime_error("error");
            }


            //react by the match function:
            switch (choose) {
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
        return ;
    }


}



void Client::upload()
{
    for (int i = 0; i < 2; i++)
    {
        string message, path;
        // read
        message = clientSock->recFromServer(SIZE_READ);
        // client->socketRead(message,client->getSocket());
        printMess(message);
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



void Client::settings() {
    string message;
    message = clientSock->recFromServer(MAX_TO_GET); 
    if (msgFromServer == "") {
        return;
        throw runtime_error("error");
    }
    cout << message << endl; ///////////////changeName

    userDio->write(message);
    //cout << message << endl;
    message.clear();
    message = userDio->read();
    //getline(cin,message);
    if(message.empty()) {
        message = CONTINUEALGORITEN;
        clientDio->write(message);
//        if(client->socketWrite(message,client->getSocket()) < 0) {
//
//        }
        return;
    }
    clientDio->write(message);
//    if(client->socketWrite(message,client->getSocket()) < 0) {
//
//    }
    message.clear();
    message = clientDio->read();
    //client->socketRead(message,client->getSocket());
    if(message != "valid input") {
        userDio->write(message);
        //printToScreen(message);
    }
}



// /// @brief checks if file can be open
// /// @param path file path
// /// @param openFile ifstream
// /// @return true is can open.
// bool openFile(string &path, ifstream &openFile){
//     openFile.open(path);
//     retur openFile.is_open();
// }



