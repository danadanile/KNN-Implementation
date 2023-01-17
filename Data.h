#ifndef DATA_H_
#define DATA_H_
#include <cstring>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include "VectorMap.h"
#include "DistanceType.h"
#include "VectorUnclassified.h"
using namespace std;

class Data {
    /// @brief distance type by int.
    string disName;
    int k;
    int disType;
    VectorUnclassified* test;
    VectorMap* train;
    bool trainIsInit;
    bool testIsInit;
    bool isClassified;

public:
    Data();
    string getDisName();
    int getK();
    void setK(int newK);
    void setDisName(string newDisName);
    void setDisType(int newDisType);
    VectorUnclassified* getTest();
    VectorMap* getTrain();
    bool getTestIsInit();
    bool getTrainIsInit();
    void setTrainIsInit(bool b);
    void setTestIsInit(bool b);
    void setTest(string fname);
    void setTrain(string fname);
    void classifyData();
};
#endif