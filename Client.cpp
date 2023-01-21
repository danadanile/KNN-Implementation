#include "Client.h"
#include "ClientSocket.h"
#include <iostream>
#include <sstream>
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

void Client::printMsg(string s){
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
        cout << "i" << i << endl;
        string message, path;

        //READ DESCRIPTION TASK:
        message = clientSock->recFromServerSize(SIZE_READ);
        printMsg(message);

        //GET PATH FROM USER:
        getFromUser(path);
        cout<<path<<endl;

        //TRY OPEN THE FILE:
        ifstream openFile;
        openFile.open(path);
        printMsg("open");
        if (!openFile.is_open()){
            message = "invalid input.\n";
            printMsg(message);
        }
        else
        {
            message = "Succeed";
            printMsg(message);
        }
        string mess=message;

        //SEND-IF SUCCEED:
        addZeros(message);
        clientSock->sendToServer(message);

        //IF NOT SUCCEED-TREAT:
        if (mess == "invalid input.\n"){
            return;
        }

        //SEND THE FILE BY ROWS:
        string buffer;
        while (openFile)
        {
            cout<<"start read"<<endl;
            buffer.clear();
            getline(openFile, buffer);
            addZeros(buffer);
            cout<<buffer<<endl;
            if(buffer== "00000000000"){
                cout<<"end while"<<endl;
                break;
            }
            clientSock->sendToServer(buffer);
        }

        //SEND FINISH OPEN THE FILE:
        buffer.clear();
        buffer = "file end";
        addZeros(buffer);
        clientSock->sendToServer(buffer);

        //GET THAT ALL UPLOAD IN SRVER:
        buffer.clear();
        buffer = clientSock->recFromServerSize(SIZE_READ);

        printMsg(buffer); // print complete or not
        cout << "here8" << endl;
        if (buffer == "invalid input.\n"){
            return;
        }
    }
    cout << "here9" << endl;
}

void Client::settings()
{
    //print the current settings:
    string message;
    message = clientSock->recFromServerSize(SIZE_READ);
    printMsg(message);
    message.clear();

    //get the new settings from user:
    getFromUser(message);

    //Enter-no changes:
    if (message.empty()){
        message = "continue";
        addZeros(message);
        clientSock->sendToServer(message);
        cout<<"ret in client"<<endl;
        return;
    }
    ////K and Distance in message:
    addZeros(message);
    clientSock->sendToServer(message);
    message.clear();

    ////Server return Validation:
    message = clientSock->recFromServerSize(SIZE_READ);
    if (message != "valid") {
        printMsg(message);
    }
    printMsg("i client return from func settings");
    return;

}
void Client::classifyData() {
    string message;
    cout<<"before recive"<<endl;
    message = clientSock->recFromServerSize(SIZE_READ);
    printMsg(message);
}
void Client::display() {
    string message;
    message = clientSock->recFromServerSize(SIZE_READ);
    printMsg(message);
}

void Client::download(){
    cout<<"before"<<endl;
    string message = clientSock->recFromServerSize(SIZE_READ);
    cout<<"after"<<endl;
    cout<<message<<endl;
    if(message=="please upload data\n" || message=="please classify the data\n") {
        printMsg(message);
        return;
    }
    else {
        cout<<"get path"<<endl;
        string path;
        getline(cin, path);
        thread thread(&Client::writeToFile, this, path, message);
        thread.detach();
    }
}


void Client::writeToFile(const string& path, const string& result) {
    std::ofstream oFile;
    oFile.open(path);
    if (oFile.is_open()) {
        oFile << result;
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

            cout << "before getting menu from server" << endl;

            //get the menu from server:
            msgFromServer = clientSock->recFromServerSize(SIZE_READ);
            printMsg(msgFromServer);

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

            msgFromServer = clientSock->recFromServerSize(SIZE_READ);
            if(msgFromServer=="invalid input"){
                continue;
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
                    classifyData();
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
