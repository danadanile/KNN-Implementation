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
#include "ClientSocket.h"
#define MAX_TO_GET 4096
using namespace std;

/// @brief insert to vec the input from userInput
/// @param vec
/// @param userInput
void getInput(vector<string> &vec, string userInput)
{
    string token;
    stringstream X(userInput);
    while (getline(X, token, ' '))
    {
        string param = token;
        vec.push_back(param);
    }
}

/// @brief prepare input lenght string for sending to client. represent by 10 chars.
/// @param input from user
void addZeros(string &input)
{
    int inputLength = input.length();
    // declare a stream object
    string str = to_string(inputLength);
    input.insert(0, str); // Inserts str2 in str1 starting from 0 index of str1
    int addZero = 10 - CheckFuncs::count_digit(inputLength);
    input.insert(0, addZero, '0'); // insert 0 addZero times in position 0;
}

/// @brief which number simbolized distance name.
enum Choise
{
    AUC = 1,
    MAN = 2,
    CHB = 3,
    CAN = 4,
    MIN = 5
};

int main(int argc, char **argv)
{

    if (argc != 3)
    {
        cout << "invalid argument" << endl;
        return 0;
    }

    // check the port.
    int port = -1;
    string strPort = string(argv[2]);
    if (ClientSocket::isPort(strPort))
    {
        port = stoi(argv[2]);
    }
    if (port == -1)
    {
        cout << "the port is not valid." << endl;
        return 0;
    }

    try
    {
        ClientSocket cli(port, argv[1]);
        while (true)
        {
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
