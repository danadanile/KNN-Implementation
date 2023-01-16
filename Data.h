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
    VectorMap train;
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
    Data(string fname, string disNum, int k, DistanceType disType);
    string getDisName();
    int getk();
    void setK(int newK);
    void setDisName(string newDisName);
    void setDisType(int newDisType);
    VectorMap* getVectorMap();
    VectorUnclassified* getTest();
    bool getTestIsInit();
    bool getTrainIsInit();
    void setTrainIsInit();
    void setTestIsInit();
    void setTest(string fname);
    void setTrain(string fname);

};
#endif