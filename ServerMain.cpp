#include <sstream>
#include "DistanceType.h"
#include "VectorMap.h"
#include "Server.h"
#include "CheckFuncs.h"
#include <cstdlib>
#define P 2
#define CHAR_SUM_INT 10

using namespace std;

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

    // check num of arg.
    if (argc != 3)
    {
        cout << "invalid argument" << endl;
        return 0;
    }
   

    // create vector map by the file.
    string fileName = argv[1];
    VectorMap mapObj(fileName);
    if (mapObj.getSizeMap() == 0)
    {
        return 0;
    }

    // check the port.
    int port = -1;
    string strPort = string(argv[2]);
 
    if (Server::IsPort(strPort))
    {
        port = stoi(argv[2]);
    }
    else{
        return 0;
    }
    if (port == -1)
    {
        cout << "invalid argument" << endl;
        return 0;
    }

    // create server .
    Server ser(port);
    while (true)
    {
        try
        {
            // enter new client.
            ser.enterClient();
            while (true)
            {
                // receve input from client and div it to vector string.
                try
                {
                    string strClient = "";
                    strClient = ser.RecFromClient(CHAR_SUM_INT); // client input.
                    if (strClient == "-1")
                    {
                        break;
                    }
                    //cout << strClient << endl;
                    vector<string> vClient;
                    stringstream ss(strClient);
                    while (getline(ss, strClient, ' '))
                    {
                        vClient.push_back(strClient);
                    }

                    // save vector (parameter 1):
                    vector<double> vec;
                    for (int i = 0; i <= vClient.size() - 3; i++) // 2 argument to disName and 'k'.
                    {
                        if (CheckFuncs::isNumber(vClient[i]))
                        {
                            double num = stod(vClient[i]);
                            vec.push_back(num);
                        }
                        else
                        {
                            throw invalid_argument("invalid input");
                            //break;
                        }
                    }

                    // save distance name (parameter 2):
                    string disName = vClient[vClient.size() - 2];
                    int disNum = 0;
                    if (disName != "AUC" && disName != "MAN" && disName != "CHB" && disName != "CAN" && disName != "MIN")
                    {
                        throw invalid_argument("invalid input");
                    }
                    // convert enums to number
                    static map<string, Choise> const table = {{"AUC", Choise::AUC}, {"MIN", Choise::MIN}, {"MAN", Choise::MAN}, {"CHB", Choise::CHB}, {"CAN", Choise::CAN}};
                    auto it = table.find(disName);
                    if (it != table.end())
                    {
                        disNum = it->second;
                    }

                    // save k arg (parameter 3):
                    int k = 0;
                    string checkK = vClient[vClient.size() - 1];
                    if (CheckFuncs::checkKValid(checkK) == true)
                    {
                        k = stoi(checkK);
                    }
                    else
                    {
                        throw invalid_argument("invalid input");
                    }

                    if (k > mapObj.getSizeMap())
                    {
                        throw invalid_argument("invalid input");
                        return 0;
                    }
                    if (vec.empty() || (vec.size() != mapObj.GetVectorLength()))
                    {
                        throw invalid_argument("invalid input");
                    }
                    else
                    {
                        string classified = mapObj.knnFunc(vec, disNum, k);
                        ser.sendToClient(classified);
                    }
                }
                catch (const invalid_argument &er)
                {
                    string error = er.what();
                    ser.sendToClient(error);
                    continue;
                }
            }
            ser.closeClient();
        }
        catch (const runtime_error &er)
        { // to exit the client
            cout << er.what() << endl;
            // sent message
            continue;
        }
    }
    // close
    ser.closeServer();
    return 0;
}
