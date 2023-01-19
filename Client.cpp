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
#define SIZE_READ 10
using namespace std;

Client::Client(ClientSocket *clientS)
{
    // clientSock = new ClientSocket();
}

string Client::printMess(string s)
{
    cout << s << endl;
}
string Client::getFromUser(string s)
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



void Client::start()
{

    try
    {
        while (true)
        {
            string msgFromServer, input;
            // int socketCommWithServer = client->getSocket();
            // get menu
            msgFromServer = clientDio->read();
            // client->socketRead(msg, socketCommWithServer);
            // print menu
            userDio->write(msg);
            // printToScreen(msg);
            input.clear();
            // return choose
            input = userDio->read();
            // input = getInput();
            clientDio->write(input);
            // client->socketWrite(input, socketCommWithServer);
            // wait for checking validation choose
            msg.clear();
            msg = clientDio->read();
            // client->socketRead(msg, socketCommWithServer);
            // choose was wrong
            if (msg == "invalid input")
            {
                userDio->write(msg);
                // printToScreen(msg);
                continue;
            }
            int choose = stoi(input);
            // int choose = validInt(input, choose);
            if (choose == 8)
            {
                return;
            }
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
            }

            string userInput;
            getline(cin, userInput);
            if (userInput.empty())
            {
                cout << "invalid input" << endl;
                continue;
            }
            if (userInput == "-1")
            {
                break;
            }
            vector<string> vec;
            getInput(vec, userInput);

            // if we get less than 3 parameters from user
            if (vec.size() < 3)
            {
                cout << "invalid input" << endl;
                continue;
            }

            string dis_input = vec[vec.size() - 2];
            string k_input = vec[vec.size() - 1];

            if (CheckFuncs::checkKValid(k_input))
            {
                int k = stoi(k_input);
            }

            else
            {
                cout << "invalid input" << endl;
                continue;
            }

            if (dis_input != "AUC" && dis_input != "MAN" && dis_input != "CHB" && dis_input != "CAN" & dis_input != "MIN")
            {
                cout << "invalid input" << endl;
                continue;
            }

            bool flag = 0;
            int vectorSize = vec.size();
            for (int i = 0; i < vectorSize - 2; i++)
            {
                if (!CheckFuncs::isNumber(vec[i]))
                { // check if
                    cout << "invalid input" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                continue;
            }

            addZeros(userInput);
            cli.sendToServer(userInput);
            cout << cli.recFromServer(MAX_TO_GET) << endl;
        }
        string finish = "-1";
        addZeros(finish);
        cli.sendToServer(finish);
        cli.closeClient();
        return 0;
    }
    catch (const runtime_error &er)
    { // to exit the client
        cout << er.what() << endl;
        return 0;
    }
}

/// @brief checks if file can be open
/// @param path file path
/// @param openFile ifstream
/// @return true is can open.
bool openFile(string &path, ifstream &openFile)
{
    openFile.open(path);
    retur openFile.is_open();
}

bool Client::upload()
{
    string mess, path;
    mess = clientDio->read();
    // client->socketRead(message,client->getSocket());
    printTo(mess);
    getline(cin, path);
    ifstream openFile;
    if (!openFile(path, openFile))
    {
        mess = "invalid input";
    }
    else
    {
        mess = "suceed";
    }
    clientDio->write(mess);
    // client->socketWrite(message,client->getSocket());
    if (mess == "invalid input")
    {
        // cout << message << endl;
        userDio->write(mess);
        return false;
    }
    string buffer;
    while (openFile)
    {
        buffer.clear();
        getline(openFile, buffer);
        clientDio->write(buffer);
        // client->socketWrite(buffer,client->getSocket());
    }
    buffer = "end of file";
    clientDio->write(buffer);
    // client->socketWrite(buffer,client->getSocket());
    buffer.clear();
    buffer = clientDio->read();
    // client->socketRead(buffer,client->getSocket());
    cout << buffer << endl;
    if (buffer == "invalid input")
    {
        return false;
    }
    return true;
}